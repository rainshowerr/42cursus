/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:05:10 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/10 22:30:25 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./so_long.h"
#include <stdio.h>

int key_hook(int keycode, t_vars *vars, t_param *param)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == W)
		param->y--;
	else if (keycode == A)
		param->x--;
	else if (keycode == S)
		param->y++;
	else if (keycode == D)
		param->x++;
	return (0);
}

void	destroy_map()
{
	write(1, "error\nbad map -_-\n", 18);
	exit(0);
}

void init_map_info(t_map_info	*map_info)
{
	map_info->row = 0;
	map_info->col = 0;
	map_info->exit = 0;
	map_info->collectible = 0;
	map_info->start = 0;
}

// 지도가 몇줄인지 체크하면서 직사각형 모양이 아닌지 확인!
void	map_square_check(t_map_info	*map_info)
{
	int 	fd;
	char	*line;

	fd = open("./map.ber", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		destroy_map();
	if (line[ft_strlen(line) - 1] == '\n')
		map_info->col = ft_strlen(line) - 1;
	else
		map_info->col = ft_strlen(line);
	free(line);
	while(line)
	{
		map_info->row++;
		line = get_next_line(fd);
		if (line)
		{
			if (line[ft_strlen(line) - 1] == '\n' && (int)ft_strlen(line) != map_info->col + 1)
			{
				free(line);
				destroy_map();
			}
			else if (line[ft_strlen(line) - 1] != '\n' && (int)ft_strlen(line) != map_info->col)
			{
				free(line);
				destroy_map();
			}
		}
		free(line);
	}
	close(fd);
}

void	check_char(t_map_info *map_info, char c)
{
	if (c ==  'C')
		map_info->collectible++;
	else if (c == 'E')
		map_info->exit++;
	else if (c == 'P')
		map_info->start++;
	else if (c != '0' && c != '1')
		destroy_map();
}

// 벽, 출구, 물고기, 시작지점 체크
void	map_error_check(t_map_info *map_info, char	**map)
{
	int	i;
	int	j;

	i = 0;
	while(i < map_info->row)
	{
		j = 0;
		while(j < map_info->col)
		{
			if ((i == 0 || j == 0 || i == map_info->row - 1 || j == map_info->col - 1) && (map[i][j] != '1'))
				destroy_map();
			check_char(map_info, map[i][j]);
			j++;
		}
		i++;
	}
	if (map_info->collectible < 1 || map_info->exit < 1 || map_info->start != 1)
		destroy_map();
}

char	**read_map(t_map_info *map_info, char *fname)
{
	int		fd;
	char	*line;
	char	**map;
	int		idx;

	map_square_check(map_info);
	fd = open(fname, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * map_info->row);
	idx = 0;
	while(idx < map_info->row)
	{
		map[idx] = (char *)malloc(map_info->col + 1);
		line = get_next_line(fd);
		strcpy(map[idx], line);
		idx++;
	}
	close(fd);
	return (map);
}

void	show_map(char **map, t_map_info *map_info)
{
	for(int i = 0; i < map_info->row; i++)
	{
		for (int j = 0; j < map_info->col; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void	set_image(t_vars* vars, t_images* images)
{
	images->snow = mlx_xpm_file_to_image(vars->mlx, "./images/snow.xpm", &images->width, &images->height);
	images->tree = mlx_xpm_file_to_image(vars->mlx, "./images/tree.xpm", &images->width, &images->height);
	images->slime = mlx_xpm_file_to_image(vars->mlx, "./images/slime.xpm", &images->width, &images->height);
	images->exit = mlx_xpm_file_to_image(vars->mlx, "./images/exit.xpm", &images->width, &images->height);
}

void print_map(t_vars* vars, t_images* images, t_map_info *map_info, char **map)
{
	int	i;
	int	j;

	set_image(vars, images);
	i = 0;
	while(i < map_info->row)
	{
		j = 0;
		while(j < map_info->col)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, images->snow, 64 * j, 64 * i);
			if (map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, images->tree, 64 * j, 64 * i);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, images->exit, 64 * j, 64 * i);
			/*
			else if (map[i][j] == 'C');
			*/
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, images->slime, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_vars		vars;
	t_map_info	map_info;
	t_images	images;
	char		**map;

	init_map_info(&map_info);
	ac = 0;
	map = read_map(&map_info, av[1]);
	map_error_check(&map_info, map);
	show_map(map, &map_info);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 64 * map_info.col, 64 * map_info.row, "so_long");
	mlx_key_hook(vars.win, key_hook, &vars);
	print_map(&vars, &images, &map_info, map);
	mlx_loop(vars.mlx);
}

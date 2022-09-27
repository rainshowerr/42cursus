/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:05:10 by seoshin           #+#    #+#             */
/*   Updated: 2022/09/27 22:35:48 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./so_long.h"
#include <stdio.h>

/*
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
*/

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
			if (line[ft_strlen(line) - 1] == '\n' && ft_strlen(line) != map_info->col + 1)
			{
				free(line);
				destroy_map();
			}
			else if (line[ft_strlen(line) - 1] != '\n' && ft_strlen(line) != map_info->col)
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
	if (c == '0' || c == '1');
	else if (c ==  'C')
		map_info->collectible++;
	else if (c == 'E')
		map_info->exit++;
	else if (c == 'P')
		map_info->start++;
	else
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

char	**read_map(t_map_info *map_info)
{
	int		fd;
	char	*line;
	char	**map;
	int		idx;

	map_square_check(map_info);
	fd = open("./map.ber", O_RDONLY);
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

void map_init(t_vars* vars, t_images* images, char **map)
{

}

int main(void)
{
	t_vars		vars;
	t_map_info	map_info;
	t_images	images;
	char		**map;

	init_map_info(&map_info);
	map = read_map(&map_info);
	map_error_check(&map_info, map);
	show_map(map, &map_info);
	
	/*
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");

	map_init(&vars, &images, map);

	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);
	return (0);
	*/
}

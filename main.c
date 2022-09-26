/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:05:10 by seoshin           #+#    #+#             */
/*   Updated: 2022/09/26 22:40:22 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./so_long.h"

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
void	map_count_row(t_map_info	*map_info)
{
	int 	fd;
	char	*line;

	fd = open("./map.ber", O_RDONLY);
	line = get_next_line(fd);
	map_info->col = ft_strlen(line);
	while(line)
	{
		map_info->row++;
		line = get_next_line(fd);
		if (map_info->col != ft_strlen(line))
		{
			close(fd);
			destroy_map();
		}
	}
}

char	**read_map(t_map_info *map_info)
{
	int		fd;
	char	*line;
	char	**map;
	int		idx;

	map_count_row(map_info);
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

#include <stdio.h>
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

int main(void)
{
	t_vars		vars;
	t_map_info	map_info;
	char		**map;

	init_map_info(&map_info);
	map = read_map(&map_info);
	show_map(map, &map_info);
	
	/*
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");


	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);
	*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:05:10 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/18 21:25:31 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./so_long.h"
#include <stdio.h>

void	w_move(t_game *game)
{
	if (game->map[game->param.x - 1][game->param.y] == 'C')
		game->get++;
	if ((game->map)[(game->param).x - 1][(game->param).y] == '0'
	|| game->map[game->param.x - 1][game->param.y] == 'C')
	{
		game->map[game->param.x][game->param.y] = '0';
		game->param.x--;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		printf("%d\n", game->move);
		print_map(game);
	}
	if (((game->map[(game->param).x - 1][(game->param).y] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x - 1][(game->param).y] == 'K')
		exit(0);
}

void	a_move(t_game *game)
{
	if (game->map[game->param.x][game->param.y - 1] == 'C')
		game->get++;
	if ((game->map)[(game->param).x][(game->param).y - 1] == '0'
	|| game->map[game->param.x][game->param.y - 1] == 'C')
	{
		game->map[game->param.x][game->param.y] = '0';
		game->param.y--;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		printf("%d\n", game->move);
		print_map(game);
	}
	else if (((game->map[(game->param).x][(game->param).y - 1] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x][(game->param).y - 1] == 'K')
		exit(0);
}

void	s_move(t_game *game)
{
	if (game->map[game->param.x + 1][game->param.y] == 'C')
		game->get++;
	if ((game->map)[(game->param).x + 1][(game->param).y] == '0'
	|| game->map[game->param.x + 1][game->param.y] == 'C')
	{
		game->map[game->param.x][game->param.y] = '0';
		game->param.x++;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		printf("%d\n", game->move);
		print_map(game);
	}
	if (((game->map[(game->param).x + 1][(game->param).y] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x + 1][(game->param).y] == 'K')
		exit(0);
}

void	d_move(t_game *game)
{
	if (game->map[game->param.x][game->param.y + 1] == 'C')
		game->get++;
	if ((game->map)[(game->param).x][(game->param).y + 1] == '0'
	|| game->map[game->param.x][game->param.y + 1] == 'C')
	{
		game->map[game->param.x][game->param.y] = '0';
		game->param.y++;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		printf("%d\n", game->move);
		print_map(game);
	}
	if (((game->map[(game->param).x][(game->param).y + 1] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x][(game->param).y + 1] == 'K')
		exit(0);
}

int key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == W)
		w_move(game);
	else if (keycode == A)
		a_move(game);
	else if (keycode == S)
		s_move(game);
	else if (keycode == D)
		d_move(game);
	return (0);
}

void	destroy_map()
{
	write(1, "error\nbad map -_-\n", 18);
	exit(0);
}

void	init_param(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(i < game->row)
	{
		j = 0;
		while(j < game->col)
		{
			if (game->map[i][j] == 'P')
			{
				game->param.x = i;
				game->param.y = j;
				return;
			}
			j++;
		}
		i++;
	}
}

void init_game(t_game *game)
{
	game->row = 0;
	game->col = 0;
	game->exit = 0;
	game->collectible = 0;
	game->get = 0;
	game->start = 0;
	game->move = 0;
}

// 지도가 몇줄인지 체크하면서 직사각형 모양이 아닌지 확인!
void	map_square_check(t_game	*game)
{
	int 	fd;
	char	*line;

	fd = open("./map.ber", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		destroy_map();
	if (line[ft_strlen(line) - 1] == '\n')
		game->col = ft_strlen(line) - 1;
	else
		game->col = ft_strlen(line);
	free(line);
	while(line)
	{
		game->row++;
		line = get_next_line(fd);
		if (line)
		{
			if (line[ft_strlen(line) - 1] == '\n' && (int)ft_strlen(line) != game->col + 1)
			{
				free(line);
				destroy_map();
			}
			else if (line[ft_strlen(line) - 1] != '\n' && (int)ft_strlen(line) != game->col)
			{
				free(line);
				destroy_map();
			}
		}
		free(line);
	}
	close(fd);
}

void	check_char(t_game *game, char c)
{
	if (c ==  'C')
		game->collectible++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
		game->start++;
	else if (c != '0' && c != '1')
		destroy_map();
}

// 벽, 출구, 물고기, 시작지점 체크
void	map_error_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(i < game->row)
	{
		j = 0;
		while(j < game->col)
		{
			if ((i == 0 || j == 0 || i == game->row - 1 || j == game->col - 1) && (game->map[i][j] != '1'))
				destroy_map();
			check_char(game, game->map[i][j]);
			j++;
		}
		i++;
	}
	if (game->collectible < 1 || game->exit < 1 || game->start != 1)
		destroy_map();
}

char	**read_map(t_game *game, char *fname)
{
	int		fd;
	char	*line;
	char	**map;
	int		idx;

	map_square_check(game);
	fd = open(fname, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * game->row);
	idx = 0;
	while(idx < game->row)
	{
		map[idx] = (char *)malloc(game->col + 1);
		line = get_next_line(fd);
		strcpy(map[idx], line);
		idx++;
	}
	close(fd);
	return (map);
}

void	show_map(char **map, t_game *game)
{
	for(int i = 0; i < game->row; i++)
	{
		for (int j = 0; j < game->col; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void	set_image(t_game *game)
{
	(game->images).snow = mlx_xpm_file_to_image(game->mlx, "./images/snow.xpm", &((game->images).width), &((game->images).height));
	(game->images).tree = mlx_xpm_file_to_image(game->mlx, "./images/tree.xpm", &((game->images).width), &((game->images).height));
	(game->images).slime = mlx_xpm_file_to_image(game->mlx, "./images/slime2.xpm", &((game->images).width), &((game->images).height));
	(game->images).exit = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm", &((game->images).width), &((game->images).height));
}

void print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(i < game->row)
	{
		j = 0;
		while(j < game->col)
		{
			mlx_put_image_to_window(game->mlx, game->win, (game->images).snow, 64 * j, 64 * i);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, (game->images).tree, 64 * j, 64 * i);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, (game->images).exit, 64 * j, 64 * i);
			/*
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, (game->images).collectible, 64 * j, 64 * i);
			else if (game->map[i][j] == 'K')
				mlx_put_image_to_window(game->mlx, game->win, (game->images).enemy, 64 * j, 64 * i);
			*/
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, (game->images).slime, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_game		game;

	init_game(&game);
	ac = 0;
	game.map = read_map(&game, av[1]);
	map_error_check(&game);
	init_param(&game);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 64 * game.col, 64 * game.row, "so_long");
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_hook, &game);
	set_image(&game);
	print_map(&game);
	mlx_loop(game.mlx);

}

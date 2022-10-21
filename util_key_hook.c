/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:56:17 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/21 18:42:54 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_move(t_game *game)
{
	if ((game->map)[(game->param).x - 1][(game->param).y] == '0'
	|| game->map[game->param.x - 1][game->param.y] == 'C')
	{
		if (game->map[game->param.x - 1][game->param.y] == 'C')
			game->get++;
		game->map[game->param.x][game->param.y] = '0';
		game->param.x--;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		ft_putnbr_n_newline(game->move);
		print_map(game);
	}
	else if (((game->map[(game->param).x - 1][(game->param).y] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x - 1][(game->param).y] == 'K')
	{
		game->move++;
		ft_putnbr_n_newline(game->move);
		exit(0);
	}
}

void	a_move(t_game *game)
{
	if ((game->map)[(game->param).x][(game->param).y - 1] == '0'
	|| game->map[game->param.x][game->param.y - 1] == 'C')
	{
		if (game->map[game->param.x][game->param.y - 1] == 'C')
			game->get++;
		game->map[game->param.x][game->param.y] = '0';
		game->param.y--;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		ft_putnbr_n_newline(game->move);
		print_map(game);
	}
	else if (((game->map[(game->param).x][(game->param).y - 1] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x][(game->param).y - 1] == 'K')
	{
		game->move++;
		ft_putnbr_n_newline(game->move);
		exit(0);
	}
}

void	s_move(t_game *game)
{
	if ((game->map)[(game->param).x + 1][(game->param).y] == '0'
	|| game->map[game->param.x + 1][game->param.y] == 'C')
	{
		if (game->map[game->param.x + 1][game->param.y] == 'C')
			game->get++;
		game->map[game->param.x][game->param.y] = '0';
		game->param.x++;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		ft_putnbr_n_newline(game->move);
		print_map(game);
	}
	else if (((game->map[(game->param).x + 1][(game->param).y] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x + 1][(game->param).y] == 'K')
	{
		game->move++;
		ft_putnbr_n_newline(game->move);
		exit(0);
	}
}

void	d_move(t_game *game)
{
	if ((game->map)[(game->param).x][(game->param).y + 1] == '0'
	|| game->map[game->param.x][game->param.y + 1] == 'C')
	{
		if (game->map[game->param.x][game->param.y + 1] == 'C')
			game->get++;
		game->map[game->param.x][game->param.y] = '0';
		game->param.y++;
		game->map[game->param.x][game->param.y] = 'P';
		game->move++;
		ft_putnbr_n_newline(game->move);
		print_map(game);
	}
	else if (((game->map[(game->param).x][(game->param).y + 1] == 'E') && (game->collectible == game->get))
	|| (game->map)[(game->param).x][(game->param).y + 1] == 'K')
	{
		game->move++;
		ft_putnbr_n_newline(game->move);
		exit(0);
	}
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
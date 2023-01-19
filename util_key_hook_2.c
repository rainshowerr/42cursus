/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_key_hook_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:56:17 by seoshin           #+#    #+#             */
/*   Updated: 2023/01/19 17:27:06 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_move(t_game *g)
{
	if ((g->map)[(g->param).x - 1][(g->param).y] == '0'
	|| (g->map)[(g->param).x - 1][(g->param).y] == 'C')
	{
		if ((g->map)[(g->param).x - 1][(g->param).y] == 'C')
			g->get++;
		(g->map)[g->param.x][g->param.y] = '0';
		(g->param).x--;
		(g->map)[(g->param).x][(g->param).y] = 'P';
		g->move++;
		ft_putnbr_n_newline(g->move);
		print_map(g);
	}
	else if ((((g->map)[(g->param).x - 1][(g->param).y] == 'E')
		&& (g->collectible == g->get))
		|| (g->map)[(g->param).x - 1][(g->param).y] == 'K')
	{
		g->move++;
		ft_putnbr_n_newline(g->move);
		exit(0);
	}
}

void	a_move(t_game *g)
{
	if ((g->map)[(g->param).x][(g->param).y - 1] == '0'
	|| (g->map)[(g->param).x][(g->param).y - 1] == 'C')
	{
		if ((g->map)[(g->param).x][(g->param).y - 1] == 'C')
			g->get++;
		(g->map)[(g->param).x][(g->param).y] = '0';
		(g->param).y--;
		(g->map)[(g->param).x][(g->param).y] = 'P';
		g->move++;
		ft_putnbr_n_newline(g->move);
		print_map(g);
	}
	else if ((((g->map)[(g->param).x][(g->param).y - 1] == 'E')
		&& (g->collectible == g->get))
		|| (g->map)[(g->param).x][(g->param).y - 1] == 'K')
	{
		g->move++;
		ft_putnbr_n_newline(g->move);
		exit(0);
	}
}

void	s_move(t_game *g)
{
	if ((g->map)[(g->param).x + 1][(g->param).y] == '0'
	|| (g->map)[(g->param).x + 1][(g->param).y] == 'C')
	{
		if ((g->map)[(g->param).x + 1][(g->param).y] == 'C')
			g->get++;
		(g->map)[(g->param).x][(g->param).y] = '0';
		(g->param).x++;
		g->map[(g->param).x][(g->param).y] = 'P';
		g->move++;
		ft_putnbr_n_newline(g->move);
		print_map(g);
	}
	else if ((((g->map)[(g->param).x + 1][(g->param).y] == 'E')
		&& (g->collectible == g->get))
		|| (g->map)[(g->param).x + 1][(g->param).y] == 'K')
	{
		g->move++;
		ft_putnbr_n_newline(g->move);
		exit(0);
	}
}

void	d_move(t_game *g)
{
	if ((g->map)[(g->param).x][(g->param).y + 1] == '0'
	|| (g->map)[(g->param).x][(g->param).y + 1] == 'C')
	{
		if ((g->map)[(g->param).x][(g->param).y + 1] == 'C')
			g->get++;
		(g->map)[(g->param).x][(g->param).y] = '0';
		g->param.y++;
		(g->map)[g->param.x][g->param.y] = 'P';
		g->move++;
		ft_putnbr_n_newline(g->move);
		print_map(g);
	}
	else if ((((g->map)[(g->param).x][(g->param).y + 1] == 'E')
		&& (g->collectible == g->get))
		|| (g->map)[(g->param).x][(g->param).y + 1] == 'K')
	{
		g->move++;
		ft_putnbr_n_newline(g->move);
		exit(0);
	}
}

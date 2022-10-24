/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:55:35 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/24 19:40:15 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->row)
	{
		j = 0;
		while (j < g->col)
		{
			if (g->map[i][j] == 'P')
			{
				g->param.x = i;
				g->param.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_game(t_game *g)
{
	g->row = 0;
	g->col = 0;
	g->exit = 0;
	g->collectible = 0;
	g->get = 0;
	g->start = 0;
	g->move = 0;
}

void	set_image(t_game *g)
{
	(g->images).snow = mlx_xpm_file_to_image(g->mlx, \
	"./images/snow.xpm", &((g->images).width), &((g->images).height));
	(g->images).tree = mlx_xpm_file_to_image(g->mlx, \
	"./images/tree.xpm", &((g->images).width), &((g->images).height));
	(g->images).player = mlx_xpm_file_to_image(g->mlx, \
	"./images/player.xpm", &((g->images).width), &((g->images).height));
	(g->images).exit = mlx_xpm_file_to_image(g->mlx, \
	"./images/exit.xpm", &((g->images).width), &((g->images).height));
	(g->images).enemy = mlx_xpm_file_to_image(g->mlx, \
	"./images/enemy.xpm", &((g->images).width), &((g->images).height));
	(g->images).collectible = mlx_xpm_file_to_image(g->mlx, \
	"./images/collectible.xpm", &((g->images).width), &((g->images).height));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:55:35 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/19 20:58:16 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	set_image(t_game *game)
{
	(game->images).snow = mlx_xpm_file_to_image(game->mlx, "./images/snow.xpm", &((game->images).width), &((game->images).height));
	(game->images).tree = mlx_xpm_file_to_image(game->mlx, "./images/tree.xpm", &((game->images).width), &((game->images).height));
	(game->images).slime = mlx_xpm_file_to_image(game->mlx, "./images/slime.xpm", &((game->images).width), &((game->images).height));
	(game->images).exit = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm", &((game->images).width), &((game->images).height));
	(game->images).enemy = mlx_xpm_file_to_image(game->mlx, "./images/enemy.xpm", &((game->images).width), &((game->images).height));
}
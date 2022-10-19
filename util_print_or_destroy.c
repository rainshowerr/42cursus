/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:34 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/19 20:58:58 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			*/
			else if (game->map[i][j] == 'K')
				mlx_put_image_to_window(game->mlx, game->win, (game->images).enemy, 64 * j, 64 * i);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, (game->images).slime, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

void	destroy_map()
{
	write(1, "error\nbad map -_-\n", 18);
	exit(0);
}
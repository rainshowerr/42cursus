/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_or_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:58:34 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/24 21:05:51 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->row)
	{
		j = 0;
		while (j < g->col)
		{
			print_tile(g, i, j);
			j++;
		}
		i++;
	}
}

void	print_tile(t_game *g, int i, int j)
{
	mlx_put_image_to_window(g->mlx, g->win, (g->images).snow, 64 * j, 64 * i);
	if (g->map[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, \
		(g->images).tree, 64 * j, 64 * i);
	else if (g->map[i][j] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, \
		(g->images).exit, 64 * j, 64 * i);
	else if (g->map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, \
		(g->images).collectible, 64 * j, 64 * i);
	else if (g->map[i][j] == 'K')
		mlx_put_image_to_window(g->mlx, g->win, \
		(g->images).enemy, 64 * j, 64 * i);
	else if (g->map[i][j] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, \
		(g->images).player, 64 * j, 64 * i);
}

void	destroy_map(void)
{
	write(1, "error\nwrong map -_-\n", 18);
	exit(0);
}

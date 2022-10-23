/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_key_hook_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:31:44 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/23 20:45:08 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *g)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == W)
		w_move(g);
	else if (keycode == A)
		a_move(g);
	else if (keycode == S)
		s_move(g);
	else if (keycode == D)
		d_move(g);
	return (0);
}

int	mouse_exit(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

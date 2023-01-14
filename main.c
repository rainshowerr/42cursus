/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:05:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/01/14 21:46:22 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int ac, char **av)
{
	t_game		g;

	init_game(&g);
	if (ac < 2)
		return (0);
	g.map = read_map(&g, av[1]);
	map_error_check(&g);
	init_param(&g);
	bfs(&g);
	free_all(&g);
	init_game(&g);
	g.map = read_map(&g, av[1]);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 64 * g.col, 64 * g.row, "so_long");
	mlx_hook(g.win, X_EVENT_KEY_RELEASE, 0, &key_hook, &g);
	mlx_hook(g.win, X_EVENT_KEY_EXIT, 0, &mouse_exit, &g);
	set_image(&g);
	print_map(&g);
	mlx_loop(g.mlx);
	free_all(&g);
	return (0);
}

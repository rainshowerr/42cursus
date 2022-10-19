/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:05:10 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/19 21:36:16 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"


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

int main(int ac, char **av)
{
	t_game		game;

	init_game(&game);
	ac = 0;
	game.map = read_map(&game, av[1]);
	map_error_check(&game);
	init_param(&game);
	printf("ㅋㅋ");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 64 * game.col, 64 * game.row, "so_long");
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_hook, &game);
	set_image(&game);
	print_map(&game);
	mlx_loop(game.mlx);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:36:38 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/19 21:36:11 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
//# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

# define X_EVENT_KEY_RELEASE	3

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_param {
	int	x;
	int	y;
}t_param;

typedef struct s_images {
	void	*snow;
	void	*tree;
	void	*slime;
	void	*collectible;
	void	*enemy;
	void	*exit;
	int		width;
	int		height;
}t_images;

typedef struct s_game{
	void		*mlx;
	void		*win;
	char		**map;
	int			row;
	int			col;
	int			exit;
	int			get;
	int			collectible;
	int			start;
	int			move;
	t_param		param;
	t_images	images;
}t_game;

char	*strcpy(char *dst, const char *src);
int		key_hook(int keycode, t_game *game);
void	destroy_map();
void	init_game(t_game *game);
void	init_param(t_game *game);
void	map_square_check(t_game	*game);
void	check_char(t_game *game, char c);
void	map_error_check(t_game *game);
char	**read_map(t_game *game, char *fname);
void	show_map(char **map, t_game *game);
void	set_image(t_game *game);
void	print_map(t_game *game);
void	w_move(t_game *game);
void	a_move(t_game *game);
void	s_move(t_game *game);
void	d_move(t_game *game);

#endif
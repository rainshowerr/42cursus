/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:36:38 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/24 19:40:22 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17

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
	void	*player;
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

void	ft_putnbr_n_newline(int n);
char	*ft_strcpy(char *dst, const char *src);
void	destroy_map(void);
void	init_param(t_game *g);
void	init_game(t_game *g);
void	map_square_check(t_game	*g, char *fname);
void	check_char(t_game *g, char c);
void	map_error_check(t_game *g);
char	**read_map(t_game *g, char *fname);
int		check_len(char *line);
void	free_some(t_game *g, int row);
void	free_all(t_game *g);
void	set_image(t_game *g);
void	print_map(t_game *g);
void	print_tile(t_game *g, int i, int j);
int		key_hook(int keycode, t_game *g);
int		mouse_exit(t_game *g);
void	w_move(t_game *g);
void	a_move(t_game *g);
void	s_move(t_game *g);
void	d_move(t_game *g);

#endif
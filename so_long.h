/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:36:38 by seoshin           #+#    #+#             */
/*   Updated: 2023/01/14 21:34:05 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include <stdio.h>

# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

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

typedef struct Node
{
	int			x;
	int			y;
	struct Node	*next;
}				Node;

typedef struct Queue
{
	Node	*front;
	Node	*rear;
	int		count;
	t_game	data;
	int		i;
	int		dx;
	int		dy;
	int		x;
	int		y;
}			Queue;

char	*ft_strcpy(char *dst, const char *src);
void	ft_putnbr_n_newline(int n);
void	print_map(t_game *g);
void	print_tile(t_game *g, int i, int j);
void	destroy_map(void);
void	init_param(t_game *g);
void	init_game(t_game *g);
void	set_image(t_game *g);
void	map_square_check(t_game	*g, char *fname);
char	**read_map(t_game *g, char *fname);
void	map_error_check(t_game *g);
int		check_len(char *line);
void	check_char(t_game *g, char c);
void	free_all(t_game *g);
void	free_some(t_game *g, int row);
int		key_hook(int keycode, t_game *g);
int		mouse_exit(t_game *g);
void	w_move(t_game *g);
void	a_move(t_game *g);
void	s_move(t_game *g);
void	d_move(t_game *g);
void	init_queue(Queue *queue);
int		isEmpty(Queue *queue);
void	enqueue(Queue *queue, int x, int y);
int		dequeue(Queue *queue, int *x, int *y);
void	bfs(t_game *temp);
int		is_valid(t_game *temp, int dx, int dy, t_game *cnt);

void	test_map(t_game *temp);

#endif
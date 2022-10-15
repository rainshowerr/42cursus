/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:36:38 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/12 20:41:22 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

# define X_EVENT_KEY_RELEASE	3

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_map_info{
	int	row;
	int col;
	int exit;
	int	collectible;
	int	start;
}t_map_info;

typedef struct s_param {
	int	x;
	int	y;
}t_param;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}t_vars;

typedef struct s_images {
	void	*snow;
	void	*tree;
	void	*slime;
	void	*exit;
	int		width;
	int		height;
}t_images;

char	*strcpy(char *dst, const char *src);
int		key_hook(int keycode, t_param *param);
void	destroy_map();
void	init_map_info(t_map_info *map_info);
void	init_param(t_map_info	map_info, char **map, t_param *param);
void	map_square_check(t_map_info	*map_info);
void	check_char(t_map_info *map_info, char c);
void	map_error_check(t_map_info *map_info, char	**map);
char	**read_map(t_map_info *map_info, char *fname);
void	show_map(char **map, t_map_info *map_info);
void	set_image(t_vars* vars, t_images* images);
void print_map(t_vars* vars, t_images* images, t_map_info *map_info, char **map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:36:38 by seoshin           #+#    #+#             */
/*   Updated: 2022/09/24 22:39:44 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

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

char	*strcpy(char *dst, const char *src);

#endif
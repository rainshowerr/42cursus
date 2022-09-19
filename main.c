/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:05:10 by seoshin           #+#    #+#             */
/*   Updated: 2022/09/19 20:57:01 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "./get_next_lne/get_next_line.h"

#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->wim);
		exit(0);
	}
	else if (keycode == W)
	{

	}
	else if (keycode == A)
	{

	}
	else if (keycode == S)
	{

	}
	else if (keycode == D)
	{
		
	}
	return (0);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "winter");

	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(mlx);
	return (0);
}
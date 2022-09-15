/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:31:22 by seoshin           #+#    #+#             */
/*   Updated: 2022/09/14 19:31:27 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img_snow;
	void	*img_tree;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "winter");
	img_snow = mlx_xpm_file_to_image(mlx, "./images/snow.xpm", &img_width, &img_height);
	img_tree = mlx_xpm_file_to_image(mlx, "./images/tree.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img_snow, 0, 0);
	mlx_put_image_to_window(mlx, win, img_tree, 0, 0);
	mlx_put_image_to_window(mlx, win, img_snow, 0, 64);
	mlx_put_image_to_window(mlx, win, img_snow, 64, 0);
	mlx_put_image_to_window(mlx, win, img_snow, 64, 64);
	mlx_loop(mlx);
	return (0);
}
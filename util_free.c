/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:08:30 by seoshin           #+#    #+#             */
/*   Updated: 2022/10/24 20:09:01 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->row)
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
}

void	free_some(t_game *g, int row)
{
	int	i;

	i = 0;
	while (i <= row)
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
}

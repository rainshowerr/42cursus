/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:33:22 by seoshin           #+#    #+#             */
/*   Updated: 2023/04/03 17:51:41 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	a_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[0]);
	state_print(philo, 'f');
	while (ft_dieflag_read(philo) == 0 && ft_eatflag_read(philo) == 0)
		usleep(10);
	pthread_mutex_unlock(&philo->info->fork[0]);
}

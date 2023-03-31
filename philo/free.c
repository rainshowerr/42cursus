/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:20:17 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/31 13:47:38 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_free(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo->info->num_of_philos)
	{
		pthread_mutex_destroy(&philo->info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->info->print_mtx);
	pthread_mutex_destroy(&philo->info->fineat_mtx);
	pthread_mutex_destroy(&philo->info->lasteat_mtx);
	pthread_mutex_destroy(&philo->info->dieflag_mtx);
	pthread_mutex_destroy(&philo->info->eatflag_mtx);
	free(philo->info->fork);
	free(philo);
}

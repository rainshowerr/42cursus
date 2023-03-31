/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:31:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/31 13:47:38 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_lasteat_read(t_philo *philo)
{
	long long	value;

	pthread_mutex_lock(&philo->info->lasteat_mtx);
	value = philo->last_eat;
	pthread_mutex_unlock(&philo->info->lasteat_mtx);
	return (value);
}

int	ft_dieflag_read(t_philo *philo)
{
	int	value;

	pthread_mutex_lock(&philo->info->dieflag_mtx);
	value = philo->info->dieflag;
	pthread_mutex_unlock(&philo->info->dieflag_mtx);
	return (value);
}

int	ft_eatflag_read(t_philo *philo)
{
	int	value;

	pthread_mutex_lock(&philo->info->eatflag_mtx);
	value = philo->info->eatflag;
	pthread_mutex_unlock(&philo->info->eatflag_mtx);
	return (value);
}

int	ft_fineat_read(t_philo *philo)
{
	int	value;

	pthread_mutex_lock(&philo->info->fineat_mtx);
	value = philo->info->fineat;
	pthread_mutex_unlock(&philo->info->fineat_mtx);
	return (value);
}

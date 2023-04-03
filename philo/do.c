/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:30:46 by seoshin           #+#    #+#             */
/*   Updated: 2023/04/03 17:47:58 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	fork_lock(philo);
	pthread_mutex_lock(&philo->info->lasteat_mtx);
	philo->last_eat = ft_time();
	pthread_mutex_unlock(&philo->info->lasteat_mtx);
	philo->eat_cnt++;
	state_print(philo, 'e');
	if (philo->eat_cnt == philo->info->must_eat)
	{
		pthread_mutex_lock(&philo->info->fineat_mtx);
		philo->info->fineat++;
		pthread_mutex_unlock(&philo->info->fineat_mtx);
	}
	ft_usleep(philo->info->time_to_eat);
	fork_unlock(philo);
}

void	ft_sleep(t_philo *philo)
{
	state_print(philo, 's');
	ft_usleep(philo->info->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	state_print(philo, 't');
	usleep(200);
}

void	state_print(t_philo *philo, char c)
{
	if (!ft_eatflag_read(philo) && !ft_dieflag_read(philo))
	{
		pthread_mutex_lock(&philo->info->print_mtx);
		if (c == 'f')
			printf("%lld %d has taken a fork\n", \
			ft_time() - philo->info->start, philo->id + 1);
		else if (c == 'e')
			printf("%lld %d is eating\n", \
			ft_time() - philo->info->start, philo->id + 1);
		else if (c == 's')
			printf("%lld %d is sleeping\n", \
			ft_time() - philo->info->start, philo->id + 1);
		else if (c == 't')
			printf("%lld %d is thinking\n", \
			ft_time() - philo->info->start, philo->id + 1);
		pthread_mutex_unlock(&philo->info->print_mtx);
	}
}

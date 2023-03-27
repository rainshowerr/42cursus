/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:30:46 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/27 17:42:52 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	fork_lock(philo);
	philo->last_eat = ft_time();
	state_print(philo, 'e');
    philo->eat_cnt++;
	if (philo->eat_cnt == philo->given->must_eat)
	{
		pthread_mutex_lock(&philo->given->eatinfo_mtx);
		philo->given->finEat++;
		pthread_mutex_unlock(&philo->given->eatinfo_mtx);
		if (philo->given->finEat == philo->given->num_of_philos)
		{
			pthread_mutex_lock(&philo->given->flag_mtx);
			philo->given->allEatFlag = 1;
			pthread_mutex_unlock(&philo->given->flag_mtx);
		}
	}
	ft_usleep(philo, philo->given->time_to_eat);
	fork_unlock(philo);
}

void	ft_sleep(t_philo *philo)
{
	state_print(philo, 's');
	ft_usleep(philo, philo->given->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	state_print(philo, 't');
	usleep(200);
}

void	state_print(t_philo *philo, char c)
{
	if (!philo->given->dieFlag && !philo->given->allEatFlag)
	{
		pthread_mutex_lock(&philo->given->print_mtx);
		if (c == 'e')
		{
			printf("%llu %d has taken a fork\n", ft_time() - philo->given->start, philo->id + 1);
			printf("%llu %d is eating\n", ft_time() - philo->given->start, philo->id + 1);
		}
		else if (c == 's')
		{
			printf("%llu %d is sleeping\n", ft_time() - philo->given->start, philo->id + 1);
		}
		else if (c == 't')
		{
			printf("%llu %d is thinking\n", ft_time() - philo->given->start, philo->id + 1);
		}
		pthread_mutex_unlock(&philo->given->print_mtx);
	}
}
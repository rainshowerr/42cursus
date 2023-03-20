/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:30:46 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/20 22:07:18 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	fork_lock(philo);
	pthread_mutex_lock(&philo->given->print);
	printf("%llu %d has taken a fork\n", ft_time() - philo->given->start, philo->id + 1);
	printf("%llu %d is eating\n", ft_time() - philo->given->start, philo->id + 1);
	pthread_mutex_unlock(&philo->given->print);
    philo->given->eat_cnt[philo->id]++;
	philo->last_eat = ft_time();
	usleep(philo->given->time_to_eat);
	fork_unlock(philo);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->given->print);
	printf("%llu %d is sleeping\n", ft_time() - philo->given->start, philo->id + 1);
	pthread_mutex_unlock(&philo->given->print);
	usleep(philo->given->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->given->print);
	printf("%llu %d is thinking\n", ft_time() - philo->given->start, philo->id + 1);
	pthread_mutex_unlock(&philo->given->print);
}
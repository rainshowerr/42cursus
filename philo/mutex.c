/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:55 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/18 21:43:42 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_given *given)
{
	int	i;

	given->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * given->num_of_philos);
	if (!given->fork)
		return (0);
	i = 0;
	while(i < given->num_of_philos)
	{
		pthread_mutex_init(&given->fork[i], NULL);
		i++;
	}
	return (1);
}

void	fork_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->given->fork[philo->left]);
	pthread_mutex_lock(&philo->given->fork[philo->right]);
}

void	fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->given->fork[philo->right]);
	pthread_mutex_unlock(&philo->given->fork[philo->left]);
}

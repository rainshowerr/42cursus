/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:55 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/27 20:36:22 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_lock(t_philo *philo)
{
	// if ((philo->id + 1) % 2 == 1)
	// {
	// 	pthread_mutex_lock(&(philo->given->fork[philo->left]));
	// 	pthread_mutex_lock(&(philo->given->fork[philo->right]));
	// }
	// else
	// {
	// 	pthread_mutex_lock(&(philo->given->fork[philo->right]));
	// 	pthread_mutex_lock(&(philo->given->fork[philo->left]));
	// }
	if (philo->id % 2 != 0)
		pthread_mutex_lock(&(philo->given->fork[philo->left]));
	else
		pthread_mutex_lock(&(philo->given->fork[philo->right]));
	printf("%llu %d has taken a fork\n", ft_time() - philo->given->start, philo->id + 1);
	if (philo->id % 2 != 0)
		pthread_mutex_lock(&(philo->given->fork[philo->right]));
	else
		pthread_mutex_lock(&(philo->given->fork[philo->left]));
	printf("%llu %d has taken a fork\n", ft_time() - philo->given->start, philo->id + 1);
}

void	fork_unlock(t_philo *philo)
{
	if ((philo->id + 1) % 2 == 1)
	{
		pthread_mutex_unlock(&(philo->given->fork[philo->left]));
		pthread_mutex_unlock(&(philo->given->fork[philo->right]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->given->fork[philo->right]));
		pthread_mutex_unlock(&(philo->given->fork[philo->left]));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:55 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/31 13:47:38 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_lock(t_philo *philo)
{
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->info->fork[philo->left]));
		state_print(philo, 'f');
		pthread_mutex_lock(&(philo->info->fork[philo->right]));
		state_print(philo, 'f');
	}
	else
	{
		pthread_mutex_lock(&(philo->info->fork[philo->right]));
		state_print(philo, 'f');
		pthread_mutex_lock(&(philo->info->fork[philo->left]));
		state_print(philo, 'f');
	}
}

void	fork_unlock(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->left]));
		pthread_mutex_unlock(&(philo->info->fork[philo->right]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->info->fork[philo->right]));
		pthread_mutex_unlock(&(philo->info->fork[philo->left]));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:55 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/20 20:36:07 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_lock(t_philo *philo)
{
	pthread_mutex_lock(&(philo->given->fork[philo->left]));
	pthread_mutex_lock(&(philo->given->fork[philo->right]));
}

void	fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->given->fork[philo->right]);
	pthread_mutex_unlock(&philo->given->fork[philo->left]);
}

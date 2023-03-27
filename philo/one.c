/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 22:33:22 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/27 17:34:53 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    a_philo(t_philo *philo)
{
    pthread_mutex_lock(&philo->given->fork[0]);
    printf("%llu %d has taken a fork\n", ft_time() - philo->given->start, philo->id + 1);
    while (philo->given->dieFlag == 0 && philo->given->allEatFlag)
        usleep(10);
    pthread_mutex_unlock(&philo->given->fork[0]);
}
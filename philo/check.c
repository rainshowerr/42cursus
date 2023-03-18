/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:08:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/18 21:17:00 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_everyone_ate(t_philo *philo)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while(i < philo[i].given->num_of_philos)
	{
		if (philo[i].eat_cnt < philo[i].given->must_eat)
			flag = 0;
		i++;
	}
	return (flag);
}

void    usleep_n_dieCheck(t_philo *philo, useconds_t microseconds)
{
    int i;

    usleep(microseconds);
    i = 0;
    while (i < philo[i].given->num_of_philos)
    {
        if (ft_time() - philo[i].last_eat > philo[i].given->time_to_die)
        {
            philo->given->flag = 1;
            break;
        }
        i++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:08:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/20 22:12:41 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_everyone_ate(t_philo *philo)
{
    int i;
    int cnt;

    i = 0;
    while(i < philo[0].given->num_of_philos)
    {
        if (philo[0].given->eat_cnt[i] < philo[0].given->must_eat)
            return (0);
        i++;
    }
    philo->given->flag = -1;
    return (1);
}

void    hungerCheck(t_philo *philo)
{
    int i;
	int	flag;

    i = 0;
	flag = 0;
    while (i < philo[0].given->num_of_philos)
    {
        if (ft_time() - philo[i].last_eat >= philo[i].given->time_to_die)
        {
            flag = i + 1;
            break;
        }
        i++;
    }
	i = 0;
	while (flag != 0 && i < philo[0].given->num_of_philos)
	{
		philo[i].given->flag = flag;
		i++;
	}
}
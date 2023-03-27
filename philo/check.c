/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:08:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/27 22:08:57 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int errCheck(int ac, char **av)
{
    if (!(ac == 5 || ac == 6))
        return (1);
    if (av[1] <= 0 || av[2] < 0 || av[3] < 0 || av[4] < 0)
		return (1);
	if (ac == 6 && av[5] < 0) // 밥 먹어야 하는 횟수가 음수인 경우
		return (1);
    return (0);
}

void    hungerCheck(t_philo *philo)
{
    int i;
    unsigned long long t;

    i = 0;
    while (i < philo->given->num_of_philos)
    {
        if (ft_time() - philo[i].last_eat >= philo->given->time_to_die)
        {
            philo->given->dieFlag = i + 1;
            pthread_mutex_lock(&philo->given->print_mtx);
            printf("%llu %d died\n", ft_time() - philo->given->start, philo->id + 1);
            pthread_mutex_unlock(&philo->given->print_mtx);
            break;
        }
        i++;
    }
}
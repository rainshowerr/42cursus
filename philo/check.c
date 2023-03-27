/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:08:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/24 21:58:26 by seoshin          ###   ########.fr       */
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

int is_everyone_eat(t_philo *philo)
{
    int i;
    int cnt;

    if (!philo->given->must_eat)
        return (0);
    if (philo->given->finEat == philo->given->num_of_philos)
		philo->given->flag = -1;
    return (1);
}

void    hungerCheck(t_philo *philo)
{
    int i;
	int	flag;

    i = 0;
	flag = 0;
    while (i < philo->given->num_of_philos)
    {
        if (ft_time() - philo[i].last_eat >= philo->given->time_to_die)
        {
            flag = i + 1;
            break;
        }
        i++;
    }
	if (flag != 0)
		philo->given->flag = flag;
}
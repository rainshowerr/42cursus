/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:32:28 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/20 21:52:34 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo **philo, t_given *given)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * given->num_of_philos);
	if (!philo)
		return (0);
	i = 0;
	while(i < given->num_of_philos)
	{
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % given->num_of_philos;
		(*philo)[i].last_eat = given->start;
		(*philo)[i].given = given;
		i++;
	}
	return (1);
}

int	init_mutex(t_given *given)
{
	int	i;

	pthread_mutex_init(&given->print, NULL);
	given->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * given->num_of_philos);
	if (!given->fork)
		return (0);
	i = 0;
	while(i < given->num_of_philos)
	{
		pthread_mutex_init(&(given->fork[i]), NULL);
		i++;
	}
	return (1);
}

int	init_given(int ac, char **av, t_given *given)
{
	int	i;
	// 예외처리 필요
	if (!(ac == 5 || ac == 6))
		return (0);
	given->num_of_philos = ft_atoi(av[1]);
	given->time_to_die = ft_atoi(av[2]);
	given->time_to_eat = ft_atoi(av[3]);
	given->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		given->must_eat = ft_atoi(av[5]);
	else
		given->must_eat = 0;
	given->flag = 0; // 플래그 초기값은 0
	given->start = ft_time();
	given->eat_cnt = (int *)malloc(sizeof(int) * given->num_of_philos);
	if (!given->eat_cnt)
		return (0);
	i = 0;
	while(i < given->num_of_philos)
		given->eat_cnt[i++] = 0;
	if (!init_mutex(given))
		return (0);
	return (1);
}
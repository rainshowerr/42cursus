/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:32:28 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/31 13:47:43 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philos);
	if (!philo)
		return (0);
	i = 0;
	while (i < info->num_of_philos)
	{
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->num_of_philos;
		(*philo)[i].last_eat = info->start;
		(*philo)[i].info = info;
		i++;
	}
	return (1);
}

int	init_mutex(t_info *info)
{
	int	i;

	pthread_mutex_init(&info->print_mtx, NULL);
	pthread_mutex_init(&info->fineat_mtx, NULL);
	pthread_mutex_init(&info->lasteat_mtx, NULL);
	pthread_mutex_init(&info->dieflag_mtx, NULL);
	pthread_mutex_init(&info->eatflag_mtx, NULL);
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* info->num_of_philos);
	if (!info->fork)
		return (0);
	i = 0;
	while (i < info->num_of_philos)
	{
		pthread_mutex_init(&(info->fork[i]), NULL);
		i++;
	}
	return (1);
}

int	init_info(int ac, char **av, t_info *info)
{
	if (errcheck(ac, av))
		return (0);
	info->num_of_philos = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = 0;
	info->fineat = 0;
	info->dieflag = 0;
	info->eatflag = 0;
	info->start = ft_time();
	if (!init_mutex(info))
		return (0);
	return (1);
}

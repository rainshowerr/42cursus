/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:18:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/31 13:47:38 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*go(void	*tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	if ((philo->id) % 2)
		usleep(1000);
	if (philo->info->num_of_philos == 1)
		a_philo(philo);
	else
	{
		while (ft_dieflag_read(philo) == 0 \
		&& ft_eatflag_read(philo) == 0)
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_thinking(philo);
		}
	}
	return (0);
}

void	wait_finish(t_philo *philo)
{
	int	i;

	while (ft_dieflag_read(philo) == 0 && ft_eatflag_read(philo) == 0)
	{
		if (ft_fineat_read(philo) == philo->info->num_of_philos)
		{
			pthread_mutex_lock(&philo->info->eatflag_mtx);
			philo->info->eatflag = 1;
			pthread_mutex_unlock(&philo->info->eatflag_mtx);
		}
		if (!ft_eatflag_read(philo))
			hungercheck(philo);
		if (ft_dieflag_read(philo) != 0 \
		|| ft_eatflag_read(philo) != 0)
			break ;
		usleep(100);
	}
	i = 0;
	while (i < philo->info->num_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	ft_free(philo);
}

void	make_thread(t_philo *philo)
{
	int	i;

	i = 0;
	philo->info->start = ft_time();
	while (i < philo->info->num_of_philos)
	{
		philo[i].last_eat = philo->info->start;
		pthread_create(&philo[i].thread, NULL, go, &(philo[i]));
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_info	info;
	t_philo	*philo;

	if (errcheck(ac, av))
		return (0);
	if (!init_info(ac, av, &info))
		return (0);
	if (!init_philo(&philo, &info))
		return (0);
	make_thread(philo);
	wait_finish(philo);
}

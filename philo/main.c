/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:18:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/27 21:57:14 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*go(void	*tmp)
{
	t_philo	*philo = (t_philo *)tmp;
	if ((philo->id + 1) % 2)
		usleep(1000);
	if (philo->given->num_of_philos == 1)
		a_philo(philo);
	else
	{
		while (philo->given->dieFlag == 0 && philo->given->allEatFlag == 0)
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

	while (philo->given->dieFlag == 0 && philo->given->allEatFlag == 0)
	{
		pthread_mutex_lock(&philo->given->flag_mtx);
		if (philo->given->finEat == philo->given->num_of_philos)
			philo->given->allEatFlag = 1;
		if (!philo->given->allEatFlag)
			hungerCheck(philo);
		if (philo->given->allEatFlag != 0 || philo->given->dieFlag != 0)
			break;
		pthread_mutex_unlock(&philo->given->flag_mtx);
		usleep(100);
	}
	i = 0;
	while (i < philo->given->num_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	make_thread(t_philo *philo)
{
	int	i;

	i = 0;
	philo->given->start = ft_time();
	while (i < philo->given->num_of_philos)
	{
		philo[i].last_eat = philo->given->start;
		pthread_create(&philo[i].thread, NULL, go, &(philo[i]));
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_given	given;
	t_philo	*philo;

	if (errCheck(ac, av))
		return (0);
	if (!init_given(ac, av, &given))
		return (0);
	if (!init_philo(&philo, &given))
		return (0);
	make_thread(philo);
	wait_finish(philo);
}


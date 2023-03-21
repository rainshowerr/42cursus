/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:18:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/21 22:15:53 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*go(void	*tmp)
{
	t_philo	*philo = (t_philo *)tmp;
	// 짝수번째는 재움
	if ((philo->id + 1) % 2 == 0)
		usleep(100);
	while (philo->given->flag == 0)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (0);
}

void	wait_finish(t_philo *philo)
{
	int	i;

	while (philo[0].given->flag == 0)
	{
		if (is_everyone_ate(philo) == 0)
			hungerCheck(philo);
		if (philo[0].given->flag != 0)
			break;
		usleep(1);
	}
	i = 0;
	while (i < philo[0].given->num_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	printf("%d\n", philo[0].given->flag);
	if (philo[0].given->flag > 0)
		printf("%llu %d died\n", ft_time() - philo[0].given->start, philo[0].given->flag);
}

void	make_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].given->num_of_philos)
	{
		philo[i].last_eat = ft_time();
		pthread_create(&philo[i].thread, NULL, go, &(philo[i]));
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_given	given;
	t_philo	*philo;

	if (!init_given(ac, av, &given))
		return (0);
	if (!init_philo(&philo, &given))
		return (0);
	make_thread(philo);
	wait_finish(philo);
	
}


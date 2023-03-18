/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:18:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/18 22:20:49 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input(int ac, char **av, t_given *given)
{
	// 예외처리 필요
	if (!(ac == 5 || ac == 6))
		exit(1);
	given->num_of_philos = ft_atoi(av[1]);
	given->time_to_die = ft_atoi(av[2]);
	given->time_to_eat = ft_atoi(av[3]);
	given->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		given->must_eat = ft_atoi(av[5]);
	else
		given->must_eat = 0;
	given->flag = 0;
	given->start = ft_time();
	mutex_init(given);
}

void	ft_cycle(t_philo *philo)
{
	while(1)
	{
		fork_lock(philo);
		printf("%llu %d has taken a fork\n", ft_time() - philo->given->start, philo->id + 1);
		printf("%llu %d is eating\n", ft_time() - philo->given->start, philo->id + 1);
		philo->last_eat = ft_time();
		philo->eat_cnt++;
		if (philo->given->must_eat > 0 && is_everyone_ate(philo))
		{
			philo->given->flag = 1;
			break;
		}
		usleep_n_dieCheck(philo, philo->given->time_to_eat);
		fork_unlock(philo);
		printf("%llu %d is sleeping", ft_time() - philo->given->start, philo->id + 1);
		usleep_n_dieCheck(philo, philo->given->time_to_sleep);
		printf("%llu %d is thinking\n", ft_time() - philo->given->start, philo->id + 1);
	}
}

void	*go(void	*tmp)
{
	t_philo	*philo = (t_philo *)tmp;
	printf("%d created\n", philo->id);
	// 짝수번째는 재움
	if (philo->id % 2 == 0)
		usleep(1000);
	ft_cycle(philo);
	return (0);
}

void	ft_thread(t_philo *philo)
{
	int	i;

	i = 0;
	printf("%dt\n", philo[0].given->num_of_philos);
	while(i < philo[0].given->num_of_philos)
	{
		printf("%dz\n", philo[0].given->num_of_philos);
		pthread_create(&philo[i].thread, NULL, go, &philo[i]);
		i++;
	}
	i = 0;
	while(philo->given->flag == 1 && i < philo->given->num_of_philos)
	{
		pthread_detach(philo[i].thread);
		i++;
	}
}

int	philo_init(t_philo **philo, t_given *given)
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
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].given = given;
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_given	given;
	t_philo	*philo;

	input(ac, av, &given);
	if (!philo_init(&philo, &given))
		return (0);
	ft_thread(philo);
}
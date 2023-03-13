/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:18:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/13 20:08:07 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_given	*input(int ac, char **av, t_given *given)
{
	// 예외처리 필요
	if (!(ac == 5 || ac == 6))
		exit(1);
	given->num_of_philos = ft_atoi(av[1]);
	given->time_to_die = ft_atoi(av[2]);
	given->time_to_eat = ft_atoi(av[3]);
	given->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		given->must_eat = ft_atoi(av[5]);
	return (given);
}

void	*go(void	*tmp)
{
	t_sopher	*sopher = (t_sopher *)tmp;
	// 짝수번째는 재움
	if (sopher->id % 2 == 0)
		usleep(1000);
	
}

void	make_thread(t_given *given, t_philo *philo)
{
	int	i;

	i = 0;
	while(i < given->num_of_philos)
	{
		pthread_create(&philo->sopher[i], NULL, go, &philo->sopher[i]);
		i++;
	}
}

void	sopher_init(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo->given.num_of_philos)
	{
		philo->sopher[i].id = i;
		philo->sopher[i].left = i;
		philo->sopher[i].right = (i + 1) % philo->given.num_of_philos;
		// philo->sopher[i].last_eat
		philo->sopher[i].eat_cnt = 0;
		i++;
	}

}

void	fork_init(t_philo *philo)
{
	int	i;

	philo->fork = (int *)malloc(sizeof(int) * philo->given.num_of_philos);
	i = 0;
	while(i < philo->given.num_of_philos)
	{
		philo->fork[i] = 1;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_philo	philo;

	input(ac, av, &philo.given);
	philo.sopher = (pthread_t *)malloc(sizeof(pthread_t) * philo.given.num_of_philos);
	make_thread(&philo.given, philo.sopher);
	fork_init(&philo);
	
}
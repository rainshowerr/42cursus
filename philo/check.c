/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:08:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/04/03 18:25:59 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_str(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && !('0' <= av[i][j] && av[i][j] <= '9')
				&& !(av[i][j] == '+'))
				return (1);
			if (j != 0 && !('0' <= av[i][j] && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	errcheck(int ac, char **av)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		return (1);
	if (av[1] <= 0 || av[2] < 0 || av[3] < 0 || av[4] < 0)
		return (1);
	if (ac == 6 && av[5] < 0)
		return (1);
	if (is_str(ac, av))
		return (1);
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}

void	hungercheck(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->num_of_philos)
	{
		if (ft_time() - ft_lasteat_read(&philo[i]) >= philo->info->time_to_die)
		{
			pthread_mutex_lock(&philo->info->dieflag_mtx);
			philo->info->dieflag = philo[i].id + 1;
			pthread_mutex_unlock(&philo->info->dieflag_mtx);
			pthread_mutex_lock(&philo->info->print_mtx);
			printf("%lld %d died\n", \
			ft_time() - philo->info->start, philo->id + 1);
			pthread_mutex_unlock(&philo->info->print_mtx);
		}
		if (philo->info->dieflag)
			break ;
	i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:08:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/31 13:50:34 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errcheck(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (1);
	if (av[1] <= 0 || av[2] < 0 || av[3] < 0 || av[4] < 0)
		return (1);
	if (ac == 6 && av[5] < 0)
		return (1);
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
			state_print(&philo[i], 'd');
		}
		if (philo->info->dieflag)
			break ;
	i++;
	}
}

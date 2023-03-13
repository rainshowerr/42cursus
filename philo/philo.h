/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:10:12 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/13 21:44:34 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int	ft_atoi(const char *str);

typedef struct s_given
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
} t_given;

typedef struct s_sopher
{
	int			id;
	int			left;
	int			right;
	int			last_eat;
	int			eat_cnt;
	pthread_t	thread;

} t_sopher;

typedef struct s_philo
{
	t_given		given;
	t_sopher	*sopher;
	int			*fork;
} t_philo;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:10:12 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/18 21:43:40 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_given
{
	int					num_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	unsigned long long	start;
	int					flag;
	pthread_mutex_t		*fork;
} t_given;

typedef struct s_philo
{
	t_given				*given;
	int					id;
	int					left;
	int					right;
	int					last_eat;
	int					eat_cnt;
	pthread_t			thread;
} t_philo;


// check.c
int		is_everyone_ate(t_philo *philo);
void    usleep_n_dieCheck(t_philo *philo, useconds_t microseconds);
// mutex.c
int		mutex_init(t_given *given);
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);
// utils.c
unsigned long long	ft_time(void);
int		ft_atoi(const char *str);

#endif
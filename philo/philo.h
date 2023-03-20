/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:10:12 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/20 17:22:49 by seoshin          ###   ########.fr       */
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
	int					*eat_cnt;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print;
} t_given;

typedef struct s_philo
{
	t_given				*given;
	int					id;
	int					left;
	int					right;
	int					last_eat;
	pthread_t			thread;
} t_philo;


// check.c
int		is_everyone_ate(t_philo *philo);
void    mealCntCheck(t_philo *philo);
void    hungerCheck(t_philo *philo);
// init.c
int		init_philo(t_philo **philo, t_given *given);
int		init_mutex(t_given *given);
int		init_given(int ac, char **av, t_given *given);
// fork.c
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);
// cycle.c
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_thinking(t_philo *philo);
// utils.c
unsigned long long	ft_time(void);
int		ft_atoi(const char *str);

#endif
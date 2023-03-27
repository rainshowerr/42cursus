/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:10:12 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/27 15:53:48 by seoshin          ###   ########.fr       */
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
	int					finEat;
	pthread_mutex_t		*fork;
	pthread_mutex_t		print_mtx;
	pthread_mutex_t		eatinfo_mtx;
	pthread_mutex_t		check_mtx;
} t_given;

typedef struct s_philo
{
	t_given				*given;
	int					id;
	int					left;
	int					right;
	int					eat_cnt;
	unsigned long long	last_eat;
	pthread_t			thread;
} t_philo;


// check.c
int 	errCheck(int ac, char **av);
int		is_everyone_eat(t_philo *philo);
void    mealCntCheck(t_philo *philo);
void    hungerCheck(t_philo *philo);
// init.c
int		init_philo(t_philo **philo, t_given *given);
int		init_mutex(t_given *given);
int		init_given(int ac, char **av, t_given *given);
// fork.c
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);
// do.c
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_thinking(t_philo *philo);
// utils.c
void	state_print(t_philo *philo, int i);
void	ft_usleep(t_philo *philo, int time);
unsigned long long	ft_time(void);
int		ft_atoi(const char *str);
// one.c
void    a_philo(t_philo *philo);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:10:12 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/31 13:47:38 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long long		start;
	int				dieflag;
	int				eatflag;
	int				fineat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	fineat_mtx;
	pthread_mutex_t	lasteat_mtx;
	pthread_mutex_t	dieflag_mtx;
	pthread_mutex_t	eatflag_mtx;
}t_info;

typedef struct s_philo
{
	t_info		*info;
	int			id;
	int			left;
	int			right;
	int			eat_cnt;
	long long	last_eat;
	pthread_t	thread;
}t_philo;

int			errcheck(int ac, char **av);
void		mealCntCheck(t_philo *philo);
void		hungercheck(t_philo *philo);
int			init_philo(t_philo **philo, t_info *info);
int			init_mutex(t_info *info);
int			init_info(int ac, char **av, t_info *info);
void		fork_lock(t_philo *philo);
void		fork_unlock(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		state_print(t_philo *philo, char c);
void		ft_usleep(int time);
long long	ft_time(void);
int			ft_atoi(const char *str);
void		a_philo(t_philo *philo);
long long	ft_lasteat_read(t_philo *philo);
int			ft_dieflag_read(t_philo *philo);
int			ft_eatflag_read(t_philo *philo);
int			ft_fineat_read(t_philo *philo);
void		ft_free(t_philo *philo);

#endif
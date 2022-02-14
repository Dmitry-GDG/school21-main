/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:30:53 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/12 07:20:42 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int				qty_phil;
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	int				qty_times;
	unsigned long	t_start;
}					t_data;

typedef struct s_phil
{
	int				nbr;
	int				pers_qty_times;
	unsigned long	pers_t_last_eat;
	t_data			data;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*mute_game;
	pthread_mutex_t	m_chk_death;
	pthread_t		threads_phil;
}					t_phil;

typedef struct s_game
{
	t_phil			*phil;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	mute_game;
	t_data			data;
}					t_game;

int				my_atoi(char *str);
void			chck_death_phils(t_game *game);
int				my_print_mssg(char *mssg);
unsigned long	real_time(void);
int				my_return_mssg(t_game *game, int sign);
int				start_game(t_game *game);
void			my_usleep(int time);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:30:53 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/14 14:33:33 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <signal.h>

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
	int				pers_die;
	int				pers_qty_times;
	unsigned long	pers_t_last_eat;
	t_data			data;
	sem_t			*s_mute_game;
	sem_t			*s_forks;
	pid_t			pid;
}					t_phil;

typedef struct s_game
{
	t_phil			*phil;
	t_data			data;
	sem_t			*s_forks;
	sem_t			*s_mute_game;
}					t_game;

int				my_atoi(char *str);
void			*play_game(void *arg);
int				my_print_mssg(char *mssg);
unsigned long	real_time(void);
int				my_return_mssg(t_game *game, int sign);
int				start_game(t_game *game);
void			my_usleep(int time);

#endif

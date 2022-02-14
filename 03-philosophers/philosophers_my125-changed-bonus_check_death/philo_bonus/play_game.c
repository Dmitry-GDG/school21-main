/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:50:24 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/14 14:35:03 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	taking_forks(t_phil *phil)
{
	if ((phil->data.qty_times != -1) && \
	(phil->pers_qty_times >= phil->data.qty_times))
		return (0);
	if (phil->data.qty_phil == 1)
	{
		printf("%lu %d has taken a fork\n", \
		real_time() - phil->data.t_start, phil->nbr + 1);
		phil->pers_die = 1;
		my_usleep(phil->data.t_die);
		printf("%lu %d died\n", \
		real_time() - phil->data.t_start, phil->nbr + 1);
		return (0);
	}
	sem_wait(phil->s_forks);
	sem_wait(phil->s_mute_game);
	printf("%lu %d has taken a fork\n%lu %d has taken a fork\n%lu %d is \
eating\n", real_time() - phil->data.t_start, phil->nbr + 1, \
		real_time() - phil->data.t_start, phil->nbr + 1, \
		real_time() - phil->data.t_start, phil->nbr + 1);
	phil->pers_qty_times++;
	phil->pers_t_last_eat = real_time();
	sem_post(phil->s_mute_game);
	my_usleep(phil->data.t_eat);
	sem_post(phil->s_forks);
	return (1);
}

static int	sleepig_thinking(t_phil *phil)
{
	if ((phil->data.qty_times != -1) && \
	(phil->pers_qty_times >= phil->data.qty_times))
		return (0);
	sem_wait(phil->s_mute_game);
	printf("%lu %d is sleeping\n", real_time() - phil->data.t_start, \
		phil->nbr + 1);
	sem_post(phil->s_mute_game);
	if (real_time() + phil->data.t_sleep >= phil->pers_t_last_eat + \
	phil->data.t_die)
	{
		my_usleep(phil->pers_t_last_eat + phil->data.t_die - real_time());
		sem_wait(phil->s_mute_game);
		phil->pers_die = 1;
		return (0);
	}
	my_usleep(phil->data.t_sleep);
	sem_wait(phil->s_mute_game);
	printf("%lu %d is thinking\n", real_time() - phil->data.t_start, \
		phil->nbr + 1);
	sem_post(phil->s_mute_game);
	return (1);
}

static void	*chck_death(void *arg)
{
	t_phil	*phil;

	phil = (t_phil *)arg;
	while (1)
	{
		if (real_time() - phil->pers_t_last_eat >= phil->data.t_die)
		{
			printf("%lu %d died\n", real_time() - phil->data.t_start, \
				phil->nbr + 1);
			phil->pers_die = 1;
			exit (1);
		}
		if (phil->pers_die == 1)
			break ;
		usleep(1);
		if ((phil->data.qty_times != -1) && \
		(phil->pers_qty_times >= phil->data.qty_times))
			break ;
	}
	return (NULL);
}

void	*play_game(void *arg)
{
	t_phil			*phil;
	pthread_t		threads_phil;

	phil = (t_phil *)arg;
	if (pthread_create(&threads_phil, NULL, &chck_death, phil))
		exit (1);
	while (!(phil->pers_die))
	{
		if (!(taking_forks(phil)))
		{
			if (phil->pers_die == 1)
				exit (1);
			exit (0);
		}
		if (!(sleepig_thinking(phil)))
		{
			if (phil->pers_die == 1)
				exit (1);
			exit (0);
		}
	}
	pthread_join(threads_phil, NULL);
	if (phil->pers_die == 1)
		exit(1);
	exit(0);
}

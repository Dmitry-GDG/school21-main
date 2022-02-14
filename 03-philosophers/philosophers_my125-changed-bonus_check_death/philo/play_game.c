/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:50:24 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/12 07:45:04 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	taking_forks(t_phil *phil)
{
	if ((phil->data.qty_times != -1) && \
	(phil->pers_qty_times >= phil->data.qty_times))
		return (0);
	pthread_mutex_lock(phil->l_fork);
	pthread_mutex_lock(phil->mute_game);
	printf("%lu %d has taken a fork\n", real_time() - phil->data.t_start, \
		phil->nbr + 1);
	pthread_mutex_unlock(phil->mute_game);
	if (phil->data.qty_phil == 1)
		return (0);
	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->mute_game);
	printf("%lu %d has taken a fork\n%lu %d is eating\n", \
		real_time() - phil->data.t_start, phil->nbr + 1, \
		real_time() - phil->data.t_start, phil->nbr + 1);
	pthread_mutex_unlock(phil->mute_game);
	pthread_mutex_lock(&phil->m_chk_death);
	phil->pers_qty_times++;
	phil->pers_t_last_eat = real_time();
	pthread_mutex_unlock(&phil->m_chk_death);
	my_usleep(phil->data.t_eat);
	pthread_mutex_unlock(phil->l_fork);
	pthread_mutex_unlock(phil->r_fork);
	return (1);
}

static int	sleepig_thinking(t_phil *phil)
{
	if ((phil->data.qty_times != -1) && \
	(phil->pers_qty_times >= phil->data.qty_times))
		return (0);
	pthread_mutex_lock(phil->mute_game);
	printf("%lu %d is sleeping\n", real_time() - phil->data.t_start, \
		phil->nbr + 1);
	pthread_mutex_unlock(phil->mute_game);
	my_usleep(phil->data.t_sleep);
	pthread_mutex_lock(phil->mute_game);
	printf("%lu %d is thinking\n", real_time() - phil->data.t_start, \
		phil->nbr + 1);
	pthread_mutex_unlock(phil->mute_game);
	return (1);
}

static void	*play_game(void *arg)
{
	t_phil	*phil;

	phil = (t_phil *)arg;
	while (1)
	{
		if (!(taking_forks(phil)))
			break ;
		if (!(sleepig_thinking(phil)))
			break ;
	}
	return (NULL);
}

int	start_game(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->data.qty_phil)
	{
		if (pthread_create(&(game->phil[i].threads_phil), NULL, &play_game, \
			&(game->phil[i])))
			return (my_return_mssg(game, 6));
		i += 2;
	}
	my_usleep(game->data.t_eat / 2);
	i = 0;
	while (i < game->data.qty_phil)
	{
		if (pthread_create(&(game->phil[i].threads_phil), NULL, &play_game, \
			&(game->phil[i])))
			return (my_return_mssg(game, 6));
		i += 2;
	}
	return (0);
}

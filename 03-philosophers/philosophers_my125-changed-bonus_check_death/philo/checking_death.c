/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:01:21 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/12 08:20:01 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	chck_death_phils1(t_game *game, int i)
{
	t_phil			*phil;
	int				j;

	phil = game->phil;
	if ((real_time() - phil[i].pers_t_last_eat > game->data.t_die))
	{
		pthread_mutex_lock(game->phil[i].mute_game);
		j = -1;
		while (++j < game->data.qty_phil)
			pthread_detach(game->phil[j].threads_phil);
		usleep (50);
		printf("%lu %d died\n", real_time() - game->data.t_start, i + 1);
		return (1);
	}
	else if (((phil->data.qty_times != -1) && \
		(phil[i].pers_qty_times >= phil->data.qty_times)))
	{
		j = -1;
		while (++j < game->data.qty_phil)
			pthread_join(game->phil[j].threads_phil, NULL);
		return (1);
	}
	return (0);
}

void	chck_death_phils(t_game *game)
{
	t_phil			*phil;
	int				i;

	phil = game->phil;
	while (1)
	{
		i = -1;
		while (++i < phil->data.qty_phil)
		{
			pthread_mutex_lock(&game->phil[i].m_chk_death);
			if (chck_death_phils1(game, i))
				return ;
			pthread_mutex_unlock(&game->phil[i].m_chk_death);
		}
	}
}

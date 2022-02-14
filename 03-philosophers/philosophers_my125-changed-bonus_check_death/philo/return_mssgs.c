/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mssgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 07:56:29 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/12 12:50:16 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	my_print_mssg(char *mssg)
{
	write (2, mssg, ft_strlen(mssg));
	return (1);
}

static void	my_return_mssg1(t_game *game, int sign)
{
	int	i;

	if (sign > 5)
	{
		i = -1;
		{
			while (++i < game->data.qty_phil)
				pthread_detach((*game).phil[i].threads_phil);
		}
	}
	i = -1;
	{
		while (++i < game->data.qty_phil)
			pthread_mutex_destroy(&game->phil[i].m_chk_death);
	}
}

int	my_return_mssg(t_game *game, int sign)
{
	int	i;

	if (sign > 1)
	{
		if (sign > 2)
		{
			if (sign > 3)
			{
				if (sign > 4)
					my_return_mssg1(game, sign);
				pthread_mutex_destroy(game->phil->mute_game);
			}
			i = -1;
			while (++i < game->data.qty_phil)
				pthread_mutex_destroy(&game->m_forks[i]);
			free(game->m_forks);
		}
		free(game->phil);
	}
	if (sign <= 6)
		return (my_print_mssg ("Error: cannot allocate memory\n"));
	return (0);
}

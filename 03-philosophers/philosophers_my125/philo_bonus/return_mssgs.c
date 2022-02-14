/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_mssgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 07:56:29 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/13 12:35:19 by trurgot          ###   ########.fr       */
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

int	my_return_mssg(t_game *game, int sign)
{
	if (sign > 1)
	{
		if (sign > 2)
		{
			if (sign > 3)
			{
				sem_close(game->s_mute_game);
				sem_unlink("mute_game");
			}
			sem_close(game->s_forks);
			sem_unlink("forks");
		}
		free(game->phil);
	}
	if (sign <= 4)
		return (my_print_mssg ("Error: cannot allocate memory\n"));
	return (0);
}

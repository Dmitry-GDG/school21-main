/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 09:50:24 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/14 14:34:01 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	end_game(t_game *game)
{
	int	i;
	int	p_id;

	i = -1;
	while (++i < game->data.qty_phil)
	{
		waitpid(-1, &p_id, 0);
		if (p_id != 0)
		{
			i = -1;
			while (++i < game->data.qty_phil)
				kill(game->phil[i].pid, SIGTERM);
			break ;
		}
	}
	i = -1;
	while (++i < game->data.qty_phil)
		kill(game->phil[i].pid, SIGKILL);
}

int	start_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->data.qty_phil)
	{
		game->phil[i].pid = fork();
		if (game->phil[i].pid < 0)
			return (4);
		if (game->phil[i].pid == 0)
		{
			play_game(&(game->phil[i]));
			usleep(10);
		}
	}
	end_game(game);
	return (0);
}

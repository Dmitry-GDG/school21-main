/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:41:36 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 15:38:19 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	my_put_empyblocks(t_solong *game)
{
	int	i;

	i = -1;
	while (i++ < 3)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall.img, i * game->bits, 0);
	}
}

void	my_put_text(t_solong *game)
{
	char	*str;

	str = ft_itoa(game->qty_steps);
	my_put_empyblocks(game);
	if (game->game_over == 0)
	{
		mlx_string_put(game->mlx, game->mlx_win, 5, 16, -1, "movement count");
		mlx_string_put(game->mlx, game->mlx_win, 7, 34, -1, str);
	}
	else
	{
		mlx_string_put(game->mlx, game->mlx_win, 5, 16, 15921152, \
			"movement count");
		mlx_string_put(game->mlx, game->mlx_win, 7, 34, 15921152, str);
		free(str);
		str = ft_itoa(game->qty_collect);
		mlx_string_put(game->mlx, game->mlx_win, 5, 77, -1, "The game over");
		mlx_string_put(game->mlx, game->mlx_win, 5, 118, 1298500, "Press Esc");
		mlx_string_put(game->mlx, game->mlx_win, 51, 136, 1298500, "for quit");
	}
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:58:15 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 16:52:27 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	my_if_closed_window(int keycode, t_solong *game)
{
	(void) keycode;
	(void) game;
	exit(0);
	return (0);
}

static int	key_hook(int keycode, t_solong *game)
{
	if ((keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2 || \
	keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124) && \
	(game->game_over == 0))
	{
		if (my_chose_step(keycode, game) == 0)
		{
			++game->qty_steps;
			my_put_text(game);
		}
	}
	if (keycode == 53)
	{
		exit (0);
	}
	return (0);
}

static void	my_print_map2(t_solong *game, int i, int j)
{
	if (game->map_components[j][i] == 'P')
	{
		game->pl_posx = i;
		game->pl_posy = j;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->player.img, i * game->bits, j * game->bits);
	}
	if (game->map_components[j][i] == 'C')
	{
		game->qty_collect_rest++;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->collect.img, i * game->bits, j * game->bits);
	}
	if (game->map_components[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit.img, i * game->bits, j * game->bits);
	if (game->map_components[j][i] == 'A')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy.img, i * game->bits, j * game->bits);
}

static void	my_print_map(t_solong *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_hght)
	{
		i = 0;
		while (game->map_components[j][i])
		{
			if (game->map_components[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall.img, i * game->bits, j * game->bits);
			if (game->map_components[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->empty.img, i * game->bits, j * game->bits);
			my_print_map2(game, i, j);
			i++;
		}
		j++;
	}
}

int	my_play_game(t_solong *game)
{
	my_print_map(game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, my_if_closed_window, game);
	mlx_loop(game->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:33:44 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 16:51:22 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	my_make_step_0(t_solong *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty.img, \
	(game->pl_posx) * game->bits, (game->pl_posy) * game->bits);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img, \
	(game->pl_posx + x) * game->bits, (game->pl_posy + y) * game->bits);
	game->map_components[game->pl_posy][game->pl_posx] = '0';
	game->map_components[game->pl_posy + y][game->pl_posx + x] = 'P';
	game->pl_posx += x;
	game->pl_posy += y;
	return (0);
}

static int	my_make_step_e(t_solong *game)
{
	if (game->qty_collect_rest == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty.img, \
		(game->pl_posx) * game->bits, (game->pl_posy) * game->bits);
		game->game_over = 1;
		return (0);
	}
	else
		return (1);
}

static int	my_make_step_c(t_solong *game, int x, int y)
{
	game->qty_collect++;
	game->qty_collect_rest--;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty.img, \
	(game->pl_posx) * game->bits, (game->pl_posy) * game->bits);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img, \
	(game->pl_posx + x) * game->bits, (game->pl_posy + y) * game->bits);
	game->map_components[game->pl_posy][game->pl_posx] = '0';
	game->map_components[game->pl_posy + y][game->pl_posx + x] = 'P';
	game->pl_posx += x;
	game->pl_posy += y;
	return (0);
}

static int	my_make_step(t_solong *game, int x, int y)
{
	if (game->map_components[game->pl_posy + y][game->pl_posx + x] == '1')
		return (1);
	else if (game->map_components[game->pl_posy + y][game->pl_posx + x] == 'C')
		return (my_make_step_c(game, x, y));
	else if (game->map_components[game->pl_posy + y][game->pl_posx + x] == 'E')
		return (my_make_step_e(game));
	else
		return (my_make_step_0(game, x, y));
}

int	my_chose_step(int keycode, t_solong *game)
{
	if (keycode == 13 || keycode == 126)
		return (my_make_step(game, 0, -1));
	if (keycode == 0 || keycode == 123)
		return (my_make_step(game, -1, 0));
	if (keycode == 1 || keycode == 125)
		return (my_make_step(game, 0, 1));
	if (keycode == 2 || keycode == 124)
		return (my_make_step(game, 1, 0));
	return (1);
}

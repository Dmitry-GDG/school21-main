/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_imgs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:46:02 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 15:36:17 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	my_store_imgs4(t_solong *game)
{
	int	x;
	int	y;

	game->enemy.img = mlx_xpm_file_to_image(game->mlx, "pics/dang1.xpm", \
	&x, &y);
	if (game->playerb.img == NULL)
		return (-1);
	game->enemy.addr = mlx_get_data_addr(game->enemy.img, \
	&game->enemy.bits_per_pixel, &game->enemy.line_length, \
	&game->enemy.endian);
	game->explosn.img = mlx_xpm_file_to_image(game->mlx, \
	"pics/explosion4.xpm", &x, &y);
	if (game->explosn.img == NULL)
		return (-1);
	game->explosn.addr = mlx_get_data_addr(game->explosn.img, \
	&game->explosn.bits_per_pixel, &game->explosn.line_length, \
	&game->explosn.endian);
	return (0);
}

static int	my_store_imgs3(t_solong *game)
{
	int	x;
	int	y;

	game->playerb.img = mlx_xpm_file_to_image(game->mlx, "pics/playerb1.xpm", \
	&x, &y);
	if (game->playerb.img == NULL)
		return (-1);
	game->playerb.addr = mlx_get_data_addr(game->playerb.img, \
	&game->playerb.bits_per_pixel, &game->playerb.line_length, \
	&game->playerb.endian);
	game->playerl.img = mlx_xpm_file_to_image(game->mlx, "pics/playerl1.xpm", \
	&x, &y);
	if (game->playerl.img == NULL)
		return (-1);
	game->playerl.addr = mlx_get_data_addr(game->playerl.img, \
	&game->playerl.bits_per_pixel, &game->playerl.line_length, \
	&game->playerl.endian);
	game->playerr.img = mlx_xpm_file_to_image(game->mlx, "pics/playerr1.xpm", \
	&x, &y);
	if (game->playerr.img == NULL)
		return (-1);
	game->playerr.addr = mlx_get_data_addr(game->playerr.img, \
	&game->playerr.bits_per_pixel, &game->playerr.line_length, \
	&game->playerr.endian);
	return (my_store_imgs4(game));
}

static int	my_store_imgs2(t_solong *game)
{
	int	x;
	int	y;

	game->exit.img = mlx_xpm_file_to_image(game->mlx, "pics/exit.xpm", &x, &y);
	if (game->exit.img == NULL)
		return (-1);
	game->exit.addr = mlx_get_data_addr(game->exit.img, \
	&game->exit.bits_per_pixel, &game->exit.line_length, \
	&game->exit.endian);
	game->exit_open.img = mlx_xpm_file_to_image(game->mlx, \
	"pics/exit_open.xpm", &x, &y);
	if (game->exit.img == NULL)
		return (-1);
	game->exit_open.addr = mlx_get_data_addr(game->exit_open.img, \
	&game->exit_open.bits_per_pixel, &game->exit_open.line_length, \
	&game->exit_open.endian);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "pics/player.xpm", &x, \
	&y);
	if (game->player.img == NULL)
		return (-1);
	game->player.addr = mlx_get_data_addr(game->player.img, \
	&game->player.bits_per_pixel, &game->player.line_length, \
	&game->player.endian);
	return (my_store_imgs3(game));
}

int	my_store_imgs(t_solong *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map_lnght * game->bits, \
		game->map_hght * game->bits, "so_long");
	game->empty.img = mlx_xpm_file_to_image(game->mlx, "pics/empty.xpm", &x, \
	&y);
	if (game->empty.img == NULL)
		return (-1);
	game->empty.addr = mlx_get_data_addr(game->empty.img, \
	&game->empty.bits_per_pixel, &game->empty.line_length, \
	&game->empty.endian);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "pics/wall.xpm", &x, &y);
	if (game->wall.img == NULL)
		return (-1);
	game->wall.addr = mlx_get_data_addr(game->wall.img, \
	&game->wall.bits_per_pixel, &game->wall.line_length, &game->wall.endian);
	game->collect.img = mlx_xpm_file_to_image(game->mlx, "pics/c.xpm", &x, &y);
	if (game->collect.img == NULL)
		return (-1);
	game->collect.addr = mlx_get_data_addr(game->collect.img, \
	&game->collect.bits_per_pixel, &game->collect.line_length, \
	&game->collect.endian);
	return (my_store_imgs2(game));
}

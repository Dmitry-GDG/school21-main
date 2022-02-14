/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:02:55 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 14:33:48 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	my_store_imgs2(t_solong *game)
{
	int	x;
	int	y;

	game->collect.img = mlx_xpm_file_to_image(game->mlx, "pics/c.xpm", \
	&x, &y);
	if (game->collect.img == NULL)
		return (-1);
	game->collect.addr = mlx_get_data_addr(game->collect.img, \
	&game->collect.bits_per_pixel, &game->collect.line_length, \
	&game->collect.endian);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "pics/exit.xpm", &x, &y);
	if (game->exit.img == NULL)
		return (-1);
	game->exit.addr = mlx_get_data_addr(game->exit.img, \
	&game->exit.bits_per_pixel, &game->exit.line_length, \
	&game->exit.endian);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "pics/player.xpm", &x, \
	&y);
	if (game->player.img == NULL)
		return (-1);
	game->player.addr = mlx_get_data_addr(game->player.img, \
	&game->player.bits_per_pixel, &game->player.line_length, \
	&game->player.endian);
	return (0);
}

static int	my_store_imgs(t_solong *game)
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
	return (my_store_imgs2(game));
}

static int	my_calc_lines(const char *map)
{
	int		result;
	int		fd;
	char	*tmp;

	result = 0;
	fd = open (map, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		result++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close (fd);
	return (result);
}

static void	init_game(t_solong *game)
{
	game->map_lnght = 0;
	game->bits = 49;
	game->qty_steps = 0;
	game->qty_collect = 0;
	game->qty_collect_rest = 0;
	game->game_over = 0;
}

int	so_long(const char *map, int fd)
{
	t_solong	game;
	int			tmp;

	init_game(&game);
	game.map_hght = my_calc_lines(map);
	if (game.map_hght < 3)
		return (my_return_mistake(4));
	game.map_components = (char **)malloc(sizeof (char *) * game.map_hght);
	if (!game.map_components)
		return (my_return_mistake(5));
	tmp = -1;
	while (tmp++ < (game.map_hght - 1))
		game.map_components[tmp] = get_next_line(fd);
	if (my_check_map(&game) < 0)
	{
		my_free_map_components(&game);
		free (game.map_components);
		return (my_return_mistake(4));
	}
	if (my_store_imgs(&game) < 0)
		return (my_return_mistake(6));
	tmp = my_play_game(&game);
	my_free_map_components(&game);
	free (game.map_components);
	return (tmp);
}

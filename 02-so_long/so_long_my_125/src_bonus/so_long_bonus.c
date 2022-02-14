/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:02:55 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 12:49:03 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

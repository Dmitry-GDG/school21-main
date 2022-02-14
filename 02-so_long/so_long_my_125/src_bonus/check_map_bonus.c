/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:02:55 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 08:55:42 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	my_check_if_exist(t_solong *game, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_hght)
	{
		j = 0;
		while (j < game->map_lnght)
		{
			if (game->map_components[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}

static int	my_check_hero(t_solong *game)
{
	int	i;
	int	j;
	int	qty;

	qty = 0;
	i = 0;
	while (i < game->map_hght)
	{
		j = 0;
		while (j < game->map_lnght)
		{
			if (game->map_components[i][j] == 'P')
			{
				if (qty == 1)
					return (-1);
				else
					qty = 1;
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	my_check_components(t_solong *game)
{
	if (my_check_hero(game) < 0)
		return (-1);
	if (my_check_if_exist(game, 'E') < 0)
		return (-1);
	if (my_check_if_exist(game, 'A') < 0)
		return (-1);
	return (my_check_if_exist(game, 'C'));
}

static int	my_check_chars(t_solong *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_hght)
	{
		j = 0;
		while (j < game->map_lnght)
		{
			if ((game->map_components[i][j] != '0') && \
			(game->map_components[i][j] != '1') && \
			(game->map_components[i][j] != 'C') && \
			(game->map_components[i][j] != 'E') && \
			(game->map_components[i][j] != 'A') && \
			(game->map_components[i][j] != 'P'))
				return (-1);
			j++;
		}
		i++;
	}
	return (my_check_components(game));
}

int	my_check_map(t_solong *game)
{
	int	tmp;

	game->map_lnght = my_strlen(game->map_components[0]);
	tmp = 0;
	while (tmp++ < (game->map_hght - 1))
	{
		if (game->map_lnght != my_strlen(game->map_components[tmp]))
			return (-1);
	}
	tmp = -1;
	while (tmp++ < (game->map_hght - 1))
	{
		if ((game->map_components[tmp][0] != '1') || \
		(game->map_components[tmp][game->map_lnght - 1] != '1'))
			return (-1);
	}
	tmp = -1;
	while (tmp++ < (game->map_lnght - 1))
	{
		if ((game->map_components[0][tmp] != '1') || \
		(game->map_components[game->map_hght - 1][tmp] != '1'))
			return (-1);
	}
	return (my_check_chars(game));
}

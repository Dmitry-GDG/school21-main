/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:40:00 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/12 16:14:52 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_free_map_components(t_solong	*game)
{
	int			hght_tmp;

	hght_tmp = -1;
	while (hght_tmp++ < game->map_hght - 1)
		free(game->map_components[hght_tmp]);
}

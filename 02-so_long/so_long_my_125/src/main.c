/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:02:55 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/14 16:10:35 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_return_mistake(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\nUse it: ./so_long maps/MAP_NAME.ber\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error\nThe extension of map must be .ber\n", 2);
	else if (i == 3)
		ft_putstr_fd("Error\nCannot read the map\n", 2);
	else if (i == 4)
		ft_putstr_fd("Error\nMap is not valid\n", 2);
	else if (i == 5)
		ft_putstr_fd("Error\nCannot allocate mamory\n", 2);
	else if (i == 6)
		ft_putstr_fd("Error\nCannot load textures\n", 2);
	return (-1);
}

static int	my_check_map_extension(const char *map)
{
	char	*tmp;

	tmp = ft_strrchr(map, '.');
	if (!tmp || ft_strcmp(tmp, ".ber"))
		return (my_return_mistake(3));
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (my_return_mistake(1));
	if (my_check_map_extension(argv[1]) == -1)
		return (my_return_mistake(2));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (my_return_mistake(3));
	if (so_long(argv[1], fd) < 0)
	{
		close (fd);
		return (-1);
	}
	close (fd);
	return (0);
}

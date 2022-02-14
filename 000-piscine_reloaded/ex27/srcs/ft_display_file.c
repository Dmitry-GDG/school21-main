/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:58:21 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/26 17:58:24 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str);

int	ft_display_file(char *file_name)
{
	char	buf[1];
	int		fd;
	int		ifread;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (3);
	}
	ifread = read(fd, buf, 1);
	while (ifread > 0)
	{
		write(1, buf, 1);
		ifread = read(fd, buf, 1);
	}
	if (ifread == -1)
	{
		ft_putstr("Cannot read file.\n");
		return (3);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	err;

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (2);
	}
	else
	{
		err = ft_display_file(argv[1]);
		if (err != 0)
		{
			return (err);
		}
	}
	return (0);
}

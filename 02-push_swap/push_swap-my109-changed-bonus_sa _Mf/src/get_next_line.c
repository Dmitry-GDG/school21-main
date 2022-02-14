/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:12:59 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 15:53:06 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_next_line(char **line)
{
	int		res;
	char	buf;
	int		i;

	i = 0;
	res = 1;
	(*line) = malloc(4);
	if (!(*line))
		return (0);
	while (res > 0 && buf != '\n')
	{
		res = read(0, &buf, 1);
		if (res > 0 && buf != '\n')
		{
			(*line)[i] = buf;
			i++;
		}
	}
	(*line)[i] = '\0';
	return (res);
}

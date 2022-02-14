/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:59:58 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 16:46:23 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != '\n'))
	{
		i++;
	}
	return (i);
}

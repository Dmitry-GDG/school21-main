/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:40:27 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/21 09:05:32 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	my_putnbr_u(unsigned int u)
{
	if (u > 9)
	{
		my_putnbr_u(u / 10);
		my_putnbr_u(u % 10);
	}
	else
	{
		u += '0';
		write(1, &u, 1);
	}
}

int	my_print_u(unsigned int u)
{
	int	outp;

	outp = 0;
	my_putnbr_u(u);
	if (u == 0)
		outp++;
	while (u > 0)
	{
		outp++;
		u /= 10;
	}
	return (outp);
}

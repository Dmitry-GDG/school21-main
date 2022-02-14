/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:04:54 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/21 09:05:20 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	my_putnbr(int d)
{
	if (d > 9)
	{
		my_putnbr(d / 10);
		my_putnbr(d % 10);
	}
	else
	{
		d += '0';
		write(1, &d, 1);
	}
}

int	my_print_d(int d)
{
	int		outp;

	outp = 0;
	if (d == -2147483648)
		outp += write(1, "-2147483648", 11);
	else
	{
		if (d == 0)
			outp++;
		if (d < 0)
		{
			outp += write(1, "-", 1);
			d *= (-1);
		}
		my_putnbr(d);
		while (d > 0)
		{
			outp++;
			d /= 10;
		}
	}
	return (outp);
}

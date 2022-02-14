/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:45:49 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/21 09:05:40 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	my_putnbr_ui(unsigned int x, int k)
{
	if (x > 15)
	{
		my_putnbr_ui(x / 16, k);
		my_putnbr_ui(x % 16, k);
	}
	else
	{
		if (x < 10)
			x += '0';
		else
		{
			if (k == 0)
				x += 'a' - 10;
			else
				x += 'A' - 10;
		}
		write (1, &x, 1);
	}
}

int	my_print_x(unsigned int x)
{
	int	outp;

	outp = 0;
	my_putnbr_ui(x, 0);
	if (x == 0)
		outp++;
	while (x > 0)
	{
		outp++;
		x /= 16;
	}
	return (outp);
}

int	my_print_xx(unsigned int x)
{
	int	outp;

	outp = 0;
	my_putnbr_ui(x, 1);
	if (x == 0)
		outp++;
	while (x > 0)
	{
		outp++;
		x /= 16;
	}
	return (outp);
}

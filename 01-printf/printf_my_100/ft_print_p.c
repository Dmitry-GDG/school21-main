/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:30:50 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/21 09:05:24 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	my_putnbr_ul(unsigned long p)
{
	if (p > 15)
	{
		my_putnbr_ul(p / 16);
		my_putnbr_ul(p % 16);
	}
	else
	{
		if (p < 10)
			p += '0';
		else
			p += 'a' - 10;
		write (1, &p, 1);
	}
}

int	my_print_p(unsigned long p)
{
	int	outp;

	outp = write(1, "0x", 2);
	my_putnbr_ul (p);
	if (p == 0)
		outp++;
	while (p > 0)
	{
		outp++;
		p /= 16;
	}
	return (outp);
}

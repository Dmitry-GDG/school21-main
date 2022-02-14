/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:15:39 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/21 09:05:10 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_print_s(char *s)
{
	int	outp;

	outp = 0;
	if (!s)
		return (write(1, "(null)", 6));
	else
	{
		while (*s)
		{
			outp += write (1, s, 1);
			s++;
		}
	}
	return (outp);
}

int	my_print_c(int c)
{
	return (write(1, &c, 1));
}

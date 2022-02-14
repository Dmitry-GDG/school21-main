/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:27:58 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/21 09:05:45 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	my_chose_print(va_list ap, char c)
{
	if (c == 'c')
		return (my_print_c(va_arg(ap, int)));
	else if (c == 's')
		return (my_print_s(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (my_print_d(va_arg(ap, int)));
	else if (c == 'u')
		return (my_print_u(va_arg(ap, unsigned int)));
	else if (c == 'p')
		return (my_print_p((unsigned long)va_arg(ap, void *)));
	else if (c == 'x')
		return (my_print_x(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (my_print_xx(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		outp;
	va_list	ap;
	int		i;

	outp = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			outp += my_chose_print(ap, format[i]);
		}
		else
			outp += write (1, &(format[i]), 1);
		i++;
	}
	va_end(ap);
	return (outp);
}

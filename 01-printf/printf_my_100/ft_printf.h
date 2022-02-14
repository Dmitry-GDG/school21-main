/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:29:19 by trurgot           #+#    #+#             */
/*   Updated: 2021/11/21 10:12:43 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		my_print_c(int c);
int		my_print_d(int d);
int		my_print_p(unsigned long p);
int		my_print_s(char *str);
int		my_print_u(unsigned int u);
int		my_print_x(unsigned int x);
int		my_print_xx(unsigned int x);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:47:33 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/27 14:30:30 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	my_chk_atoi_res(t_ps **stck, unsigned long long outp, int minus, \
	int i)
{
	if (outp > 2147483647 || ((minus == -1) && (outp > 2147483648)))
		(*stck)->err = -1;
	else
		(*stck)->a[i] = (int)outp * minus;
}

static int	my_chk_white_space(char *str, int j)
{
	while (str[j] && (str[j] == '\n' || str[j] == '\t' || str[j] == '\v' || \
		str[j] == '\r' || str[j] == '\f' || str[j] == 32))
		j++;
	return (j);
}

void	my_atoi(t_ps **stck, char *str, int i)
{
	int					j;
	int					minus;
	unsigned long long	outp;
	int					k;

	j = 0;
	j = my_chk_white_space(str, j);
	minus = 1;
	if (str[j] == '-')
		minus = -1;
	if (str[j] == '-' || str[j] == '+')
		j++;
	k = j;
	outp = 0;
	while (str[j] && str[j] >= '0' && str[j] <= '9')
	{
		outp = outp * 10 + str[j] - '0';
		j++;
	}
	my_chk_atoi_res(stck, outp, minus, i);
	j = my_chk_white_space(str, j);
	if (str[j] != '\0' || j == k)
		(*stck)->err = -1;
}

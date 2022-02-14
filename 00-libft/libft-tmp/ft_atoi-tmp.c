/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:47:33 by trurgot           #+#    #+#             */
/*   Updated: 2021/10/04 13:47:37 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	unsigned long long	outp;

	i = 0;
	minus = 1;
	outp = 0;
	while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || \
		str[i] == '\r' || str[i] == '\f' || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((minus > 0 && (outp * 10 + str[i] - '0') > 9223372036854775807ULL) || (minus < 0 && (outp * 10 + str[i] - '0') > 9223372036854775808ULL))
			return (minus == 1 ? -1 : 0);
		outp = outp * 10 + str[i] - '0';
		i++;
	}
	return ((int)outp * minus);
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char	s[1000] = "  \t\n\r\v\f   18446744073709551621";
	printf("atoi: \t\t%d\n", atoi(s));
	printf("ft_atoi:\t%d\n", ft_atoi(s));
	return (0);
}
/* Call it:
* gcc -Wall -Wextra -Werror ft_atoi.c && ./a.out */
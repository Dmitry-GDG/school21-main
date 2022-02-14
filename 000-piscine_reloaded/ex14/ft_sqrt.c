/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:22:55 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 19:22:57 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	outp;

	if (nb <= 0)
	{
		return (0);
	}
	outp = 1;
	while (outp * outp < nb)
	{
		outp++;
	}
	if (outp * outp == nb)
	{
		return (outp);
	}
	else
	{
		return (0);
	}
}

/*#include <stdio.h>
*int	main(void)
*{
*	printf("Square root of -1 is %d\n", ft_sqrt(-1));
*	printf("Square root of 0 is %d\n", ft_sqrt(0));
*	printf("Square root of 16 is %d\n", ft_sqrt(16));
*	printf("Square root of 225 is %d\n", ft_sqrt(225));
*	printf("Square root of 255 is %d\n", ft_sqrt(255));
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_sqrt.c && ./a.out */
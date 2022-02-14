/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:46:52 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 18:46:55 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	else if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else
	{
		while (nb > 1)
		{
			result *= nb;
			nb--;
		}
		return (result);
	}
}

/*#include <stdio.h>
*int	main(void)
*{
*	printf("Iterative factorial of -1 is %d\n", ft_iterative_factorial(-1));
*	printf("Iterative factorial of 0 is %d\n", ft_iterative_factorial(0));
*	printf("Iterative factorial of 5 is %d\n", ft_iterative_factorial(5));
*	printf("Iterative factorial of 12 is %d\n", ft_iterative_factorial(12));
*	printf("Iterative factorial of 13 is %d\n", ft_iterative_factorial(13));
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_iterative_factorial.c && ./a.out */
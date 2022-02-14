/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:11:59 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 19:12:03 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
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
		return (nb * ft_recursive_factorial(nb - 1));
	}
}

/*#include <stdio.h>
*int	main(void)
*{
*	printf("Recirsive factorial of -1 is %d\n", ft_recursive_factorial(-1));
*	printf("Recursive factorial of 0 is %d\n", ft_recursive_factorial(0));
*	printf("Recirsive factorial of 5 is %d\n", ft_recursive_factorial(5));
*	printf("Recursive factorial of 12 is %d\n", ft_recursive_factorial(12));
*	printf("Recursive factorial of 13 is %d\n", ft_recursive_factorial(13));
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_recursive_factorial.c && ./a.out */
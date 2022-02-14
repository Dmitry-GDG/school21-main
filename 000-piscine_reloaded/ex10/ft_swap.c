/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:39:41 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 17:39:44 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*#include <stdio.h>
*void	ft_swap(int *a, int *b);
*int	main(void)
*{
*	int	a, b;
*	a = 21;
*	b = 42;
*	printf("a = %d, b = %d\n", a, b);
*	ft_swap(&a, &b);
*	printf("after ft_swap a = %d, b = %d\n", a, b);
*	return (0);
*}*/
/*call it:
* gcc -Wall -Wextra -Werror ft_swap.c && ./a.out */
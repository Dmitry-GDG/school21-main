/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:38:37 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/26 10:38:40 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*outp;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	else
	{
		outp = malloc(sizeof(int) * (max - min));
		if (outp == NULL)
		{
			return (NULL);
		}
		i = 0;
		while (i <= (max - min - 1))
		{
			outp[i] = min + i;
			i++;
		}
		return (outp);
	}
}

/*#include <stdio.h>
*int	main(void)
*{
*	int i, a, b;
*	int	*result;
*	a = 5;
*	b = 12;
*	printf("ft_range of %d and %d is\n", a, b);
*	result = ft_range(a, b);
*	i = 0;
*	while (result[i])
*	{
*		printf("integer %d\tis placed in address %p\n", result[i], &result[i]);
*		i++;
*	}
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_range.c && ./a.out */
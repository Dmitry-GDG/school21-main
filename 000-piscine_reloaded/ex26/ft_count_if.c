/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:45:00 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/26 16:45:04 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int(*f)(char*))
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
		{
			result++;
		}
		i++;
	}
	return (result);
}

/*#include <stdio.h>
*int	ft_strlen(char *str)
*{
*	int	i;
*
*	i = 0;
*	while (str[i])
*	{
*		i++;
*	}
*	return (i);
*}
*int	main(int argc, char **argv)
*{
*	if (argc > 1)
*	{
*		printf("result of ft_count_if is: %d\n", ft_count_if(argv, ft_strlen));
*	}
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_count_if.c && /
* ./a.out gtr JJ iou yhgfd JJ j KI k g JJJ */
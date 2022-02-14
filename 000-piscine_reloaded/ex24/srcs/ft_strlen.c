/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:52:34 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 19:52:38 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
*int	main(int argc, char **argv)
*{
*	(void) argc;
*	printf("Strlen of %s = %d\n", argv[1], ft_strlen(argv[1]));
*	return (0);
*}*/
/* call it
* gcc -Wall -Wextra -Werror ft_strlen.c && ./a.out "School21" */
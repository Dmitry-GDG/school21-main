/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:00:49 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 20:00:52 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
*#include <string.h>
*int	main(int argc, char **argv)
*{
*	if (argc == 3)
*	{
*		printf("strcmp of %s and %s is %d\n", argv[1], argv[2], \
*				strcmp(argv[1], argv[2]));
*		printf("ft_strcmp of %s and %s is %d\n", argv[1], argv[2], \
*				ft_strcmp(argv[1], argv[2]));
*		return (0);
*	}
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_strcmp.c && ./a.out "asdfr" "asdfc" */
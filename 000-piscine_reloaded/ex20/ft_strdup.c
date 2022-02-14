/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:17:38 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/26 10:17:48 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	char	*outp;
	int		i;

	outp = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (outp == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		outp[i] = src[i];
		i++;
	}
	outp[i] = '\0';
	return (outp);
}

/*#include <string.h>
*#include <stdio.h>
*int	main(int argc, char **argv)
*{
*	if (argc > 1)
*	{
*		char	*str1;
*		char	*str2;
*		str1 = strdup(argv[1]);
*		str2 = ft_strdup(argv[1]);
*		printf("strdup \t\tof %s is %s\n", argv[1], str1);
*		printf("ft_strdup \tof %s is %s\n", argv[1], str2);
*		free (str1);
*		free (str2);
*		return (0);
*	}
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_strdup.c && ./a.out "School 21" */
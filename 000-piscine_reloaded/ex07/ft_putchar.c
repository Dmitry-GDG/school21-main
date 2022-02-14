/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:59:07 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 13:59:14 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*void	ft_putchar(char c);
*
*int	main(int argc, char **argv)
*{
*	(void) argc;
*	ft_putchar(*argv[1]);
*	write(1, "\n", 1);
*	return(0);
*}*/
/*call it:
* gcc -Wall -Wextra -Werror ft_putchar.c && ./a.out j */
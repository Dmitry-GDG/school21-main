/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:36:51 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 16:36:55 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}

/*#include <stdio.h>
*void	ft_is_negative(int n);
*void	my_print_combo(int i)
*{
*	printf("If %d?  -  ", i);
*	fflush(stdout); 
*}
*int	main(void)
*{
*	int	i;
*	i = 6;
*	my_print_combo(i);
*	ft_is_negative(i);
*	write(1, "\n", 1);
*	i = 0;
*	my_print_combo(i);
*	ft_is_negative(i);
*	write(1, "\n", 1);
*	i = -6;
*	my_print_combo(i);
*	ft_is_negative(i);
*	write(1, "\n", 1);
*	return (0);
*}*/
/*call it:
*gcc -Wall -Wextra -Werror ft_is_negative.c ft_putchar.c && ./a.out */
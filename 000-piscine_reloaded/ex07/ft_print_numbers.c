/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:53:30 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 14:53:33 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		ft_putchar(c);
		c++;
	}
}

/*void	ft_print_numbers(void);
*int	main(void)
*{
*	ft_print_numbers();
*	return (0);
*}*/
/*call it:
*gcc -Wall -Wextra -Werror ft_print_numbers.c ft_putchar.c && ./a.out */
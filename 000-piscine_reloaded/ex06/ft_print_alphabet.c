/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:11:37 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 14:11:42 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		ft_putchar(c);
		c++;
	}
}

/*void	ft_print_alphabet(void);
*int	main(void)
*{
*	ft_print_alphabet();
*	return (0);
*}*/
/*call it:
*gcc -Wall -Wextra -Werror ft_print_alphabet.c ft_putchar.c && ./a.out */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:42:25 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 19:42:28 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*int	main(int argc, char **argv)
*{
*	(void) argc;
*	ft_putstr(argv[1]);
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_putstr.c ft_putchar.c && ./a.out "School 21" */
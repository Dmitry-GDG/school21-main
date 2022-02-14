/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:02:39 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/26 16:02:41 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*void	ft_foreach(int *tab, int length, void(*f)(int));
*void	ft_putnbr(int nbr);
*
*int	main(void)
*{
*	int	i;
*	int	tab[1500];
*
*	i = 0;
*	while (i < 1500)
*	{
*		tab[i] = i;
*		i++;
*	}
*	ft_foreach(tab, 13, &ft_putnbr);
*	return (0);
*}*/
/* Call it:
* gcc -Wall -Wextra -Werror ft_foreach.c ft_putnbr.c  && ./a.out */
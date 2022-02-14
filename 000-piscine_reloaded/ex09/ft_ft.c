/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:12:27 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 17:12:31 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*#include <stdio.h>
*void	ft_ft(int *nbr);
*int	main(void)
*{
*	int	nbr;
*	nbr = 425;
*	printf("nbr = %d\n", nbr);
*	ft_ft(&nbr);
*	printf("after ft_ft nbr = %d\n", nbr);
*	return (0);
*}*/
/*call it:
* gcc -Wall -Wextra -Werror ft_ft.c && ./a.out */
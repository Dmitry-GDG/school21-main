/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:50:49 by dmitry            #+#    #+#             */
/*   Updated: 2021/09/25 17:50:55 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>
*int	main(void)
*{
*	int	a, b, div, mod;
*	a = 100;
*	b = 42;
*	ft_div_mod(a, b, &div, &mod);
*	printf("a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
*	return (0);
*}*/
/* call it:
* gcc -Wall -Wextra -Werror ft_div_mod.c && ./a.out */
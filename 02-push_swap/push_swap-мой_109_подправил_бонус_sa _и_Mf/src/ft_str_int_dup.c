/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_int_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:57:20 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/07 09:44:17 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_str_int_dup(const int *s1, unsigned long len)
{
	int				*outp;
	unsigned long	i;

	outp = malloc(len * sizeof(int));
	if (outp == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		outp[i] = s1[i];
		i++;
	}
	return (outp);
}

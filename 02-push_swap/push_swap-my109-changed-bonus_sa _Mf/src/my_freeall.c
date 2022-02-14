/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 07:34:53 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 10:55:45 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_struct(t_ps *stck)
{
	if (stck->a)
		free (stck->a);
	if (stck)
		free (stck);
}

void	my_dblclstclear(t_dblclst **lst, int len_lst)
{
	t_dblclst	*tmp;
	t_dblclst	*tmp2;

	tmp = *lst;
	while (len_lst-- > 0)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

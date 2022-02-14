/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:28:12 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 10:01:14 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_dblclst	*ft_dblclstfillfromstruct(t_ps *stck)
{
	t_dblclst	*outp;
	t_dblclst	*new;
	int			i;

	outp = NULL;
	i = 0;
	while (i < stck->len_a)
	{
		new = ft_dblclstinit((stck->a)[i]);
		if (new == NULL)
		{
			stck->err = -1;
			if (i > 0)
				ft_dblclstclear(&outp);
			return (NULL);
		}
		outp = ft_dblclstaddback(&outp, &new);
		i++;
	}
	return (outp);
}

static int	if_sorted(t_ps *stck)
{
	int	i;

	i = 0;
	while (i < (stck->len_a - 1))
	{
		if (stck->a[i] > stck->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	push_swap(t_ps *stck)
{
	t_dblclst	*stck_a;
	t_dblclst	**stck_b;
	t_dblclst	*tmp;

	stck_a = ft_dblclstfillfromstruct(stck);
	if (stck_a == NULL)
		return ;
	stck_b = (t_dblclst **)malloc(sizeof(t_dblclst *));
	if (stck_b == NULL)
	{
		my_dblclstclear(&stck_a, stck->len_a);
		return ;
	}
	if (if_sorted(stck) == 0)
	{
		my_index_lst(&stck_a, stck);
		my_sort_dblclst(&stck_a, stck_b, stck);
	}
	free (stck_b);
	while (stck->len_a-- > 0)
	{
		tmp = stck_a->next;
		free(stck_a);
		stck_a = tmp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch-instr_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:15:47 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 13:42:32 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push1(t_dblclst **from)
{
	(*from)->next->prev = (*from)->prev;
	(*from)->prev->next = (*from)->next;
	(*from) = (*from)->next;
}

static void	push(t_dblclst **from, t_dblclst **to, int len_from, int len_to)
{
	t_dblclst	*tmp;

	tmp = *from;
	if (len_from == 0)
		return ;
	else if (len_from == 1)
		*from = NULL;
	else
		push1(from);
	if (len_to == 0)
	{
		*to = tmp;
		(*to)->next = *to;
		(*to)->prev = *to;
	}
	else
	{
		(*to)->prev->next = tmp;
		tmp->prev = (*to)->prev;
		tmp->next = (*to);
		(*to)->prev = tmp;
	}
	*to = tmp;
}

void	c_pa(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	push(stck_b, stck_a, stck->len_b, stck->len_a);
	if (stck->len_b > 0)
	{
		++(stck->len_a);
		--(stck->len_b);
	}
	stck->counter++;
}

void	c_pb(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	push(stck_a, stck_b, stck->len_a, stck->len_b);
	if (stck->len_a > 0)
	{
		++(stck->len_b);
		--(stck->len_a);
	}
	stck->counter++;
}

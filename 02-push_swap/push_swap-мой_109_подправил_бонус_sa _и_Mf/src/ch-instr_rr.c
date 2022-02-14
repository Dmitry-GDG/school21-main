/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch-instr_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:37:01 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 13:43:03 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate(t_dblclst **lst)
{
	if (*lst && *lst != (*lst)->next)
		*lst = (*lst)->prev;
}

void	c_rra(t_dblclst **stck_a, t_ps *stck)
{
	rev_rotate(stck_a);
	stck->counter++;
}

void	c_rrb(t_dblclst **stck_b, t_ps *stck)
{
	rev_rotate(stck_b);
	stck->counter++;
}

void	c_rrr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	rev_rotate(stck_a);
	rev_rotate(stck_b);
	stck->counter++;
}

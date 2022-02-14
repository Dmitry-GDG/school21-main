/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:37:01 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/07 12:24:07 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate(t_dblclst **lst)
{
	if (*lst && *lst != (*lst)->next)
		*lst = (*lst)->prev;
}

void	rra(t_dblclst **stck_a, t_ps *stck)
{
	rev_rotate(stck_a);
	write (1, "rra\n", 4);
	stck->counter++;
}

void	rrb(t_dblclst **stck_b, t_ps *stck)
{
	rev_rotate(stck_b);
	write (1, "rrb\n", 4);
	stck->counter++;
}

void	rrr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	rev_rotate(stck_a);
	rev_rotate(stck_b);
	write (1, "rrr\n", 4);
	stck->counter++;
}

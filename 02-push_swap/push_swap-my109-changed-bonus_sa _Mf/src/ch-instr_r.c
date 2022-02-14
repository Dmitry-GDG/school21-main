/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch-instr_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:36:57 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 13:42:46 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_dblclst **lst)
{
	if (*lst && *lst != (*lst)->next)
		*lst = (*lst)->next;
}

void	c_ra(t_dblclst **stck_a, t_ps *stck)
{
	rotate(stck_a);
	stck->counter++;
}

void	c_rb(t_dblclst **stck_b, t_ps *stck)
{
	rotate(stck_b);
	stck->counter++;
}

void	c_rr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	rotate(stck_a);
	rotate(stck_b);
	stck->counter++;
}

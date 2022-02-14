/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:36:57 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/08 10:45:38 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_dblclst **lst)
{
	if (*lst && *lst != (*lst)->next)
		*lst = (*lst)->next;
}

void	ra(t_dblclst **stck_a, t_ps *stck)
{
	rotate(stck_a);
	write (1, "ra\n", 3);
	stck->counter++;
}

void	rb(t_dblclst **stck_b, t_ps *stck)
{
	rotate(stck_b);
	write (1, "rb\n", 3);
	stck->counter++;
}

void	rr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	rotate(stck_a);
	rotate(stck_b);
	write (1, "rr\n", 3);
	stck->counter++;
}

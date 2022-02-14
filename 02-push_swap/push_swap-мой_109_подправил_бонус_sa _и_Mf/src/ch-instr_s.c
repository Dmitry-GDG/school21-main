/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch-instr_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:32:19 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 19:36:48 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_dblclst **lst)
{
	if (lst == NULL)
		return ;
	else if (*lst == NULL)
		return ;
	else if ((*lst)->next == *lst)
		return ;
	else if ((*lst)->next->next == *lst)
	{
		*lst = (*lst)->next;
		return ;
	}
	else
	{
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		(*lst)->next->next->prev = (*lst);
		(*lst)->next = (*lst)->next->next;
		(*lst)->prev->next->next = (*lst);
		(*lst)->prev = (*lst)->prev->next;
		(*lst) = (*lst)->prev;
	}
}

void	c_sa(t_dblclst **stck_a, t_ps *stck)
{
	swap(stck_a);
	stck->counter++;
}

void	c_sb(t_dblclst **stck_b, t_ps *stck)
{
	swap(stck_b);
	stck->counter++;
}

void	c_ss(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	swap(stck_a);
	swap(stck_b);
	stck->counter++;
}

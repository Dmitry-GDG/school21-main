/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort_dblclst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:35:50 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 10:01:01 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_3stckba(t_dblclst **stck_a, t_ps *stck)
{
	if (((*stck_a)->val > (*stck_a)->next->val) && \
		((*stck_a)->next->next->val > (*stck_a)->val))
		sa(stck_a, stck);
	else if (((*stck_a)->val > (*stck_a)->next->val) && \
		((*stck_a)->next->val > (*stck_a)->next->next->val))
	{
		sa(stck_a, stck);
		rra(stck_a, stck);
	}
	else if (((*stck_a)->val > (*stck_a)->next->next->val) && \
		((*stck_a)->next->val < (*stck_a)->next->next->val))
		ra(stck_a, stck);
	else if (((*stck_a)->val < (*stck_a)->next->next->val) && \
		((*stck_a)->next->val > (*stck_a)->next->next->val))
	{
		sa(stck_a, stck);
		ra(stck_a, stck);
	}
	else if (((*stck_a)->val < (*stck_a)->next->val) && \
		(((*stck_a)->val > (*stck_a)->next->next->val)))
		rra(stck_a, stck);
}

static void	sort_3stckbb(t_dblclst **stck_b, t_ps *stck)
{
	if ((*stck_b)->val < (*stck_b)->next->val && \
	(*stck_b)->next->val < (*stck_b)->next->next->val)
	{
		sb(stck_b, stck);
		rrb(stck_b, stck);
	}
	else if ((*stck_b)->val > (*stck_b)->next->val && \
	(*stck_b)->val < (*stck_b)->next->next->val)
		rrb(stck_b, stck);
	else if ((*stck_b)->val < (*stck_b)->next->val && \
	(*stck_b)->val > (*stck_b)->next->next->val)
		sb(stck_b, stck);
	else if ((*stck_b)->val < (*stck_b)->next->next->val && \
	(*stck_b)->next->val > (*stck_b)->next->next->val)
		rb(stck_b, stck);
	else if ((*stck_b)->val > (*stck_b)->next->next->val && \
	(*stck_b)->next->val < (*stck_b)->next->next->val)
	{
		sb(stck_b, stck);
		rb(stck_b, stck);
	}
}

static void	fill_stck_b(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	int	i;
	int	j;
	int	k;

	i = stck->len_a;
	j = stck->len_a;
	while (i-- > 0)
	{
		if (((*stck_a)->position != (j - 3)) && \
		((*stck_a)->position != (j - 2)) && ((*stck_a)->position != (j - 1)))
			pb(stck_a, stck_b, stck);
		else if (stck->len_a != 3)
			ra(stck_a, stck);
		if (stck->len_a == 3)
			break ;
	}
	sort_3stckba(stck_a, stck);
	if ((stck->len_b == 2) && ((*stck_b)->val < (*stck_b)->next->val))
		sb(stck_b, stck);
	if (stck->len_b == 3)
		sort_3stckbb(stck_b, stck);
	k = stck->len_b;
	while (k-- > 0)
		pa(stck_a, stck_b, stck);
}

static void	my_sort_dblclst_small(t_dblclst **stck_a, t_dblclst **stck_b, \
	t_ps *stck)
{
	if (stck->len_a == 2)
		sa(stck_a, stck);
	if (stck->len_a == 3)
		sort_3stckba(stck_a, stck);
	if (stck->len_a > 3)
		fill_stck_b(stck_a, stck_b, stck);
}

void	my_sort_dblclst(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	int	i;
	int	j;

	if (stck->len_a < 7)
		my_sort_dblclst_small(stck_a, stck_b, stck);
	else
	{
		i = 0;
		while (i < stck->qtybinardigits)
		{
			j = stck->len_a;
			while (j-- > 0)
			{
				if ((*stck_a)->binar[31 - i] == '0')
					pb(stck_a, stck_b, stck);
				else
					ra(stck_a, stck);
			}
			j = stck->len_b;
			while (j-- > 0)
				pa(stck_a, stck_b, stck);
			i++;
		}
	}
}

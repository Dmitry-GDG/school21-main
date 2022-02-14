/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:30:09 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 09:47:34 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	my_qty_binardigits(int qty)
{
	int	i;

	i = 1;
	while (qty / 2)
	{
		i++;
		qty /= 2;
	}
	return (i);
}

static void	my_convert_binar(t_dblclst **stck_a, int j)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((j & (0x80000000 >> i)) == 0)
			(*stck_a)->binar[i] = '0';
		else
			(*stck_a)->binar[i] = '1';
		i++;
	}
	(*stck_a)->binar[i] = '\0';
}

static void	my_index_lst2(t_ps *stck, int *tmp, t_dblclst **stck_a)
{
	int			i;
	int			j;
	t_dblclst	*tmps;

	i = 0;
	tmps = *stck_a;
	while (i < stck->len_a)
	{
		j = 0;
		while (j < stck->len_a)
		{
			if ((tmps->val) == tmp[j])
			{
				tmps->position = j;
				my_convert_binar(&tmps, j);
			}
			j++;
		}
		i++;
		tmps = tmps->next;
	}
}

static void	my_index_lst1(t_ps *stck, int *tmp, t_dblclst **stck_a)
{
	int		i;
	int		j;
	int		tt;

	i = 0;
	while (i < stck->len_a - 1)
	{
		j = 0;
		while (j < stck->len_a - i - 1)
		{
			if (tmp[j] > tmp[j + 1])
			{
				tt = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tt;
			}
			j++;
		}
		i++;
	}
	my_index_lst2(stck, tmp, stck_a);
}

void	my_index_lst(t_dblclst **stck_a, t_ps *stck)
{
	int	*tmp;

	tmp = ft_str_int_dup(stck->a, stck->len_a);
	if (tmp == NULL)
	{
		stck->err = -1;
		return ;
	}
	my_index_lst1(stck, tmp, stck_a);
	stck->qtybinardigits = my_qty_binardigits(stck->len_a);
	free(tmp);
}

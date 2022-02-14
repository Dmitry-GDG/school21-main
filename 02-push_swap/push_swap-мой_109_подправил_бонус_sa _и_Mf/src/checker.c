/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:45:12 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 15:28:17 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	if_stck_sorted(t_dblclst *stck_a, t_ps *stck)
{
	int	len;

	len = 0;
	while (len++ < stck->len_a - 1)
	{
		if (stck_a->val > stck_a->next->val)
			return (-1);
		stck_a = stck_a->next;
	}
	return (0);
}

static void	my_make_steps(char *line, t_dblclst **stck_a, t_dblclst **stck_b, \
		t_ps *stck)
{
	if (ft_strcmp(line, "sa") == 0)
		c_sa(stck_a, stck);
	else if (ft_strcmp(line, "sb") == 0)
		c_sb(stck_b, stck);
	else if (ft_strcmp(line, "ss") == 0)
		c_ss(stck_a, stck_b, stck);
	else if (ft_strcmp(line, "pa") == 0)
		c_pa(stck_a, stck_b, stck);
	else if (ft_strcmp(line, "pb") == 0)
		c_pb(stck_a, stck_b, stck);
	else if (ft_strcmp(line, "ra") == 0)
		c_ra(stck_a, stck);
	else if (ft_strcmp(line, "rb") == 0)
		c_rb(stck_b, stck);
	else if (ft_strcmp(line, "rr") == 0)
		c_rr(stck_a, stck_b, stck);
	else if (ft_strcmp(line, "rra") == 0)
		c_rra(stck_a, stck);
	else if (ft_strcmp(line, "rrb") == 0)
		c_rrb(stck_b, stck);
	else if (ft_strcmp(line, "rrr") == 0)
		c_rrr(stck_a, stck_b, stck);
	else
		write(1, "Error\n", 6);
}

static void	my_read_actions(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		my_make_steps(line, stck_a, stck_b, stck);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

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

void	checker(t_ps *stck)
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
	my_read_actions(&stck_a, stck_b, stck);
	if ((if_stck_sorted(stck_a, stck) == 0) && stck->len_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free (stck_b);
	while (stck->len_a-- > 0)
	{
		tmp = stck_a->next;
		free(stck_a);
		stck_a = tmp;
	}
}

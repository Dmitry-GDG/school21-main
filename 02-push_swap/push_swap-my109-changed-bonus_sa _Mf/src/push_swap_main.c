/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:21:54 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 10:55:33 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	my_chk_array_dups(t_ps **stck)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*stck)->len_a)
	{
		j = i + 1;
		while (j < (*stck)->len_a)
		{
			if ((*stck)->a[i] == (*stck)->a[j])
				(*stck)->err = -1;
			j++;
		}
		i++;
	}
	(*stck)->counter = 0;
}

static void	my_fila2(t_ps **stck, int argc, char **argv, int fl)
{
	int			i;

	i = 0;
	(*stck)->len_a = argc - fl;
	(*stck)->a = (int *)malloc((sizeof(int)) * ((*stck)->len_a));
	if (!(*stck)->a)
	{
		(*stck)->err = -1;
		return ;
	}
	while (i < (*stck)->len_a)
	{
		my_atoi(stck, argv[i + fl], i);
		i++;
	}
	my_chk_array_dups(stck);
}

static void	my_fila1(t_ps **stck, char **argv)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	tmp = ft_split(argv[1], ' ');
	if (tmp == NULL)
		(*stck)->err = -1;
	i = 0;
	while (tmp[i])
		i++;
	my_fila2(stck, i, tmp, 0);
	i = 0;
	while (tmp[i])
	{
		free (tmp[i]);
		i++;
	}
	free (tmp);
}

static void	init_stack(t_ps *stck)
{
	stck->a = NULL;
	stck->err = 0;
	stck->len_a = 0;
	stck->len_b = 0;
	stck->counter = 0;
	stck->qtybinardigits = 0;
}

int	main(int argc, char **argv)
{
	t_ps	*stck;

	stck = (t_ps *)malloc(sizeof(t_ps));
	if (!stck)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	init_stack(stck);
	if (argc == 2)
		my_fila1(&stck, argv);
	else if (argc > 2)
		my_fila2(&stck, argc, argv, 1);
	if (stck->err < 0)
		write(1, "Error\n", 6);
	if ((stck->err < 0) || (argc < 2))
	{
		free_struct(stck);
		return (-1);
	}
	push_swap(stck);
	free (stck->a);
	free (stck);
	return (0);
}

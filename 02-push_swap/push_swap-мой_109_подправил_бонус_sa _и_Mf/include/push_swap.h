/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:27:14 by trurgot           #+#    #+#             */
/*   Updated: 2021/12/29 15:33:05 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_push_swap
{
	int		*a;
	int		err;
	int		len_a;
	int		len_b;
	int		counter;
	int		qtybinardigits;
}			t_ps;

void	my_atoi(t_ps **stck, char *str, int i);
void	my_dblclstclear(t_dblclst **lst, int len_lst);
void	free_struct(t_ps *stck);
void	my_index_lst(t_dblclst **stck_a, t_ps *stck);
void	push_swap(t_ps *stck);
void	my_sort_dblclst(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
int		*ft_str_int_dup(const int *s1, unsigned long len);

void	pa(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	pb(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	ra(t_dblclst **stck_a, t_ps *stck);
void	rb(t_dblclst **stck_b, t_ps *stck);
void	rr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	rra(t_dblclst **stck_a, t_ps *stck);
void	rrb(t_dblclst **stck_b, t_ps *stck);
void	rrr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	sa(t_dblclst **stck_a, t_ps *stck);
void	sb(t_dblclst **stck_b, t_ps *stck);
void	ss(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);

void	checker(t_ps *stck);
int		get_next_line(char **line);

void	c_pa(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	c_pb(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	c_ra(t_dblclst **stck_a, t_ps *stck);
void	c_rb(t_dblclst **stck_b, t_ps *stck);
void	c_rr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	c_rra(t_dblclst **stck_a, t_ps *stck);
void	c_rrb(t_dblclst **stck_b, t_ps *stck);
void	c_rrr(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);
void	c_sa(t_dblclst **stck_a, t_ps *stck);
void	c_sb(t_dblclst **stck_b, t_ps *stck);
void	c_ss(t_dblclst **stck_a, t_dblclst **stck_b, t_ps *stck);

#endif

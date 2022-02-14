/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:17:56 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/08 13:10:06 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static void	ft_send_signal(pid_t pid, int signum)
{
	if (kill (pid, signum) == -1)
		ft_putstr_fd ("The server error\n", 2);
}

static void	my_print_str(char **str, int len_mssg)
{
	int	i;

	(*str)[len_mssg] = '\0';
	i = ft_strlen(*str);
	write(1, *str, i);
	free(*str);
	*str = NULL;
	g_in_work = 0;
}

static int	my_init_str(int *i, char **str, pid_t client_pid, int len)
{
	*i = 0;
	*str = ft_calloc (len + 1, sizeof(**str));
	if (!*str)
	{
		if (kill (client_pid, SIGUSR2) == -1)
			ft_putstr_fd ("The server error\n", 2);
		return (-1);
	}
	return (1);
}

void	my_fill_str(int signum, pid_t client_pid, int len_mssg)
{
	static char	*str;
	static int	i;
	static int	counter;

	if (!str)
	{
		if (my_init_str(&i, &str, client_pid, len_mssg) == -1)
			return ;
		counter = 128;
	}
	if (signum == SIGUSR1)
		str[i] |= counter;
	counter >>= 1;
	if (!counter)
	{
		i++;
		counter = 128;
	}
	if (i == len_mssg)
	{
		my_print_str(&str, len_mssg);
		return ;
	}
	usleep(30);
	ft_send_signal(client_pid, SIGUSR1);
}

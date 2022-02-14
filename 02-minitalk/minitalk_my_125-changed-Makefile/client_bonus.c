/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:17:57 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/08 13:46:24 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk_bonus.h"

static void	my_send_bit(char c, int counter, pid_t serv_pid)
{
	if (c & counter)
	{
		if (kill (serv_pid, SIGUSR1) == -1)
			ft_putstr_fd ("Error. Cannot send message\n", 2);
	}
	else
	{
		if (kill (serv_pid, SIGUSR2) == -1)
			ft_putstr_fd ("Error. Cannot send message\n", 2);
	}
}

static void	my_message(pid_t server_pid, char *str)
{
	static char		*my_str;
	static pid_t	my_pid;
	static int		counter;

	if (!my_pid)
	{
		my_str = str;
		my_pid = server_pid;
		counter = 128;
		return ;
	}
	if (!*my_str)
		return ;
	usleep(20);
	my_send_bit(*my_str, counter, my_pid);
	counter >>= 1;
	if (!counter)
	{
		counter = 128;
		my_str++;
	}
}

static void	my_send_len_mssg(pid_t server_pid, int len)
{
	static int		len_mssg;
	static pid_t	my_pid;
	static int		counter;

	if (!len_mssg)
	{
		len_mssg = len;
		counter = 1 << 30;
		my_pid = server_pid;
	}
	if (counter)
	{
		if (counter & len_mssg)
		{
			if (kill (my_pid, SIGUSR1) == -1)
				ft_putstr_fd ("Error. Cannot send message\n", 2);
		}
		else
		{
			if (kill (my_pid, SIGUSR2) == -1)
				ft_putstr_fd ("Error. Cannot send message\n", 2);
		}
		counter >>= 1;
		usleep (30);
	}
}

static void	my_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	counter;

	(void) siginfo;
	(void) context;
	if (signum == SIGUSR2)
	{
		ft_putstr_fd ("The server busy, try again!\n", 2);
		exit(-1);
	}
	if (counter < 30)
	{
		counter++;
		my_send_len_mssg(0, 0);
		return ;
	}
	my_message(0, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				server_pid;
	unsigned int		wait_timer;

	if (argc != 3)
	{
		ft_putstr_fd ("Error. Arguments: server_PID string_to_send.\n", 2);
		return (-1);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = my_handler;
	sigemptyset (&act.sa_mask);
	if ((sigaction (SIGUSR1, &act, 0) == -1) || \
		(sigaction (SIGUSR2, &act, 0) == -1))
		ft_putstr_fd ("Cannot sent message, try again\n", 2);
	server_pid = (pid_t)ft_atoi(argv[1]);
	my_message(server_pid, argv[2]);
	my_send_len_mssg(server_pid, ft_strlen(argv[2]));
	wait_timer = 1;
	while (wait_timer > 0)
		wait_timer = sleep(1);
	return (0);
}

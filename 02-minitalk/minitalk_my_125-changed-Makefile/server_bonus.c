/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:18:15 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/08 13:49:17 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk_bonus.h"

static void	my_get_len_mssg(int signum, pid_t client_pid, int *len)
{
	static int	counter;

	if (!counter)
		counter = 1 << 30;
	if (signum == SIGUSR1)
		*len |= counter;
	counter >>= 1;
	if (kill (client_pid, SIGUSR1) == -1)
		ft_putstr_fd ("The server error\n", 2);
}

static void	my_init_new_session(pid_t *pid_in_work, siginfo_t *siginfo, \
	int *len_mssg, int *counter)
{
	*pid_in_work = siginfo->si_pid;
	*len_mssg = 0;
	*counter = 0;
	g_in_work = 1;
}

static void	my_handler(int signum, siginfo_t *siginfo, void *context)
{
	static int		len_mssg;
	static pid_t	pid_in_work;
	static int		counter;

	(void) context;
	if (!pid_in_work || pid_in_work != siginfo->si_pid)
	{
		if (g_in_work == 0)
			my_init_new_session(&pid_in_work, siginfo, &len_mssg, &counter);
		else
		{
			if (kill (siginfo->si_pid, SIGUSR2) == -1)
				ft_putstr_fd ("The server error\n", 2);
			return ;
		}
	}
	if (counter < 31)
	{
		counter ++;
		my_get_len_mssg(signum, siginfo->si_pid, &len_mssg);
		return ;
	}
	my_fill_str(signum, siginfo->si_pid, len_mssg);
}

int	main(void)
{
	struct sigaction	act;

	g_in_work = 0;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = my_handler;
	sigemptyset (&act.sa_mask);
	if ((sigaction (SIGUSR1, &act, NULL) == -1) || \
		(sigaction (SIGUSR2, &act, NULL) == -1))
		ft_putstr_fd ("The server error\n", 2);
	ft_putstr_fd("The server PID is ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}

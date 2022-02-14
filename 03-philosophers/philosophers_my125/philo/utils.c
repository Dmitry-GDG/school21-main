/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:42:53 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/08 13:16:01 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_atoi(char *str)
{
	long long	outp;
	int			i;

	i = 0;
	if (str[i] == '+')
		i++;
	outp = 0;
	while (str[i])
	{
		outp = outp * 10 + str[i] - '0';
		i++;
		if (outp > 2147483647)
			return (-1);
	}
	return (outp);
}

unsigned long	real_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((unsigned long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	my_usleep(int time)
{
	unsigned long	t_start;

	t_start = real_time();
	while (real_time() < t_start + time)
		usleep(1);
}

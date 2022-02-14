/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:31:49 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/12 07:28:48 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	my_allocate(t_game *game, t_data data)
{
	int	i;

	game->phil = malloc(sizeof(t_phil) * data.qty_phil);
	if (!game->phil)
		return (1);
	game->m_forks = malloc(sizeof(pthread_mutex_t) * data.qty_phil);
	if (!game->m_forks)
		return (2);
	i = 0;
	while (i < data.qty_phil)
	{
		if (pthread_mutex_init(&game->m_forks[i], NULL))
			return (3);
		i++;
	}
	if (pthread_mutex_init(&game->mute_game, NULL))
		return (4);
	return (0);
}

static int	my_init_game(t_game *game, t_data data)
{
	int	i;

	i = my_allocate(game, data);
	if (i > 0)
		return (i);
	game->data = data;
	while (i < data.qty_phil)
	{
		game->phil[i].nbr = i;
		game->phil[i].pers_qty_times = 0;
		game->phil[i].l_fork = &game->m_forks[i];
		game->phil[i].r_fork = &game->m_forks[i + 1];
		if (i == data.qty_phil - 1)
		{
			game->phil[i].l_fork = &game->m_forks[0];
			game->phil[i].r_fork = &game->m_forks[i];
		}
		game->phil[i].data = data;
		game->phil[i].mute_game = &game->mute_game;
		game->phil[i].pers_t_last_eat = real_time();
		if (pthread_mutex_init(&game->phil[i].m_chk_death, NULL))
			return (5);
		i++;
	}
	return (0);
}

static void	my_init_data(int c, char **v, t_data *data)
{
	data->qty_phil = (int)my_atoi(v[1]);
	data->t_die = (unsigned long)my_atoi(v[2]);
	data->t_eat = (unsigned long)my_atoi(v[3]);
	data->t_sleep = (unsigned long)my_atoi(v[4]);
	if (c == 6)
		data->qty_times = (int)my_atoi(v[5]);
	else
		data->qty_times = -1;
	data->t_start = real_time();
}

static int	my_chck_data(int c, char **v)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		j = 0;
		if (v[i][j] == '+')
			j++;
		while (v[i][j])
		{
			if (v[i][j] < '0' || v[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (my_atoi(v[1]) == -1 || my_atoi(v[2]) == -1 || my_atoi(v[3]) == -1 || \
	my_atoi(v[4]) == -1)
		return (0);
	if (c == 6 && my_atoi(v[5]) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
		return (my_print_mssg ("Error: number of arguments\n"));
	if (!my_chck_data(argc, argv))
		return (my_print_mssg ("Error: not valid arguments\n"));
	my_init_data(argc, argv, &data);
	i = my_init_game(&game, data);
	if (i)
		return (my_return_mssg(&game, i));
	i = start_game(&game);
	if (i)
		return (my_return_mssg(&game, i));
	chck_death_phils(&game);
	my_return_mssg(&game, 7);
	return (0);
}

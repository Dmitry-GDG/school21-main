/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:31:49 by trurgot           #+#    #+#             */
/*   Updated: 2022/02/13 12:28:29 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	my_allocate(t_game *game, t_data data)
{
	game->phil = malloc(sizeof(t_phil) * data.qty_phil);
	if (!game->phil)
		return (1);
	sem_unlink("forks");
	sem_unlink("mute_game");
	game->s_forks = sem_open("forks", O_CREAT, 0660, data.qty_phil / 2);
	if (game->s_forks == SEM_FAILED)
		return (2);
	game->s_mute_game = sem_open("mute_game", O_CREAT, 0660, 1);
	if (game->s_mute_game == SEM_FAILED)
		return (3);
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
		game->phil[i].pers_die = 0;
		game->phil[i].data = data;
		game->phil[i].pers_t_last_eat = real_time();
		game->phil[i].s_mute_game = game->s_mute_game;
		game->phil[i].s_forks = game->s_forks;
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
	t_game		game;
	t_data		data;
	int			i;

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
	my_return_mssg(&game, 5);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trurgot <trurgot@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:04:01 by trurgot           #+#    #+#             */
/*   Updated: 2022/01/15 16:47:04 by trurgot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_solong
{
	int		map_lnght;
	int		map_hght;
	char	**map_components;
	void	*mlx;
	void	*mlx_win;
	int		bits;
	int		qty_steps;
	int		qty_collect;
	int		qty_collect_rest;
	int		pl_posx;
	int		pl_posy;
	int		game_over;
	t_data	empty;
	t_data	wall;
	t_data	collect;
	t_data	exit;
	t_data	exit_open;
	t_data	player;
	t_data	playerb;
	t_data	playerl;
	t_data	playerr;
	t_data	enemy;
	t_data	explosn;
}			t_solong;

int		my_check_map(t_solong *game);
int		my_chose_step(int keycode, t_solong *game);
void	my_free_map_components(t_solong *game);
int		my_play_game(t_solong *game);
int		my_return_mistake(int i);
int		so_long(const char *map, int fd);
int		my_chose_step(int keycode, t_solong *game);
void	my_put_text(t_solong *game);
int		my_store_imgs(t_solong *game);
int		my_strlen(const char *s);

#endif

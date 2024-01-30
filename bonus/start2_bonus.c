/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:58:12 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:08:17 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_count(t_game *s)
{
	char	*count;
	char	*collect;

	collect = ft_itoa(s->nb_collec);
	count = ft_itoa(s->mov);
	mlx_string_put(s->mlx, s->mlx_win, 15, 15, 0x000FFD700, "MOVE");
	mlx_string_put(s->mlx, s->mlx_win, 85, 15, 0x000FFD700, count);
	mlx_string_put(s->mlx, s->mlx_win, 15, 30, 0x000FFD700, "COLLECT");
	mlx_string_put(s->mlx, s->mlx_win, 90, 30, 0x000FFD700, collect);
	free(collect);
	free(count);
}

void	init_value(t_game *s, t_map *map)
{
	s->nb_collec = 0;
	s->max = 0;
	s->mov = 0;
	s->bat_x = 0;
	s->bat_y = 0;
	s->end_x = 0;
	s->end_y = 0;
	s->nb_bat = get_nb_bat(map);
	s->nb_e = get_nb_e(map);
}

void	display_map(t_game *game, t_map *map)
{
	fond(game, map);
	mur(game, map);
}

int	ft_close2(t_game *s)
{
	mlx_destroy_window(s->mlx, s->mlx_win);
	exit(0);
}

void	pushfire(t_game *s)
{
	int	i;
	int	j;

	s->tp = s->dir;
	i = s->pos_y / 64;
	j = s->pos_x / 64;
	if (s->tp)
	{
		s->fireball = xpm_to_img(*s, s->rel_leftfireball);
		if (s->map1[i][j - 1] == 'Q')
			fk_norm2(s, 1, i, j);
		else if (s->map1[i][j - 1] != 'C' && s->map1[i][j - 1] != 'E'
			&& s->map1[i][j - 1] != '1' && s->map1[i][j - 1] != 'Q')
			s->map1[i][j - 1] = '.';
	}
	else
	{
		s->fireball = xpm_to_img(*s, s->rel_fireball);
		if (s->map1[i][j + 1] == 'Q')
			fk_norm2(s, 0, i, j);
		else if (s->map1[i][j + 1] != 'C' && s->map1[i][j + 1] != 'E'
			&& s->map1[i][j + 1] != '1' && s->map1[i][j + 1] != 'Q')
			s->map1[i][j + 1] = '.';
	}
}

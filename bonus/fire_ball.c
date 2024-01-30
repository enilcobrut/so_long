/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_ball.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:45:48 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 11:48:45 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

void	move_fireleft(t_game *s)
{
	int	i;
	int	j;

	i = s->fire_y / 64;
	j = s->fire_x / 64;
	if (s->map1[i][j - 1] == 'Q')
		is_bat(s, i, j, 1);
	else if (s->map1[i][j - 1] != 'E' && s->map1[i][j - 1] != 'C'
		&& s->map1[i][j - 1] != '1' && s->map1[i][j - 1] != 'P')
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->fire_x, s->fire_y);
		s->map1[i][j] = '0';
		s->fire_x -= 64;
		s->map1[i][j - 1] = '.';
	}
	else
		s->map1[i][j] = '0';
}

void	move_fireright(t_game *s)
{
	int	i;
	int	j;

	i = s->fire_y / 64;
	j = s->fire_x / 64;
	if (s->map1[i][j + 1] == 'Q')
		is_bat(s, i, j, 0);
	else if (s->map1[i][j + 1] != 'E' && s->map1[i][j + 1] != 'C'
		&& s->map1[i][j + 1] != '1' && s->map1[i][j + 1] != 'P')
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->fire_x, s->fire_y);
		s->map1[i][j] = '0';
		s->fire_x += 64;
		s->map1[i][j + 1] = '.';
	}
	else
		s->map1[i][j] = '0';
}

void	move_fire(t_game *s)
{
	static int	loop = 0;

	if (++loop == 5)
	{
		if (s->tp)
			move_fireleft(s);
		else
			move_fireright(s);
		loop = 0;
	}
}

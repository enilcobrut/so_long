/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normebonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:59:58 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/28 17:11:47 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fk_norm2(t_game *s, int bol, int i, int j)
{
	s->nb_bat--;
	if (bol)
		s->map1[i][j - 1] = '0';
	else
		s->map1[i][j + 1] = '0';
}

void	is_bat(t_game *s, int i, int j, int bol)
{
	s->nb_bat--;
	if (bol)
	{
		s->map1[i][j] = '0';
		s->map1[i][j - 1] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->fire_x - 64, s->fire_y);
	}
	else
	{
		s->map1[i][j] = '0';
		s->map1[i][j + 1] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->fire_x + 64, s->fire_y);
	}
}

void	is_letter(t_game *s, int i, int j, int index)
{
	if (index == 1)
	{
		s->pos_x = j * 64;
		s->pos_y = i * 64;
		ft_animate(*s);
	}
	else if (index == 2)
	{
		s->end_x = j * 64;
		s->end_y = i * 64;
		ft_animate2(*s);
	}
	else if (index == 3)
	{
		s->x = j * 64;
		s->y = i * 64;
		ft_animate4(*s);
	}
}

void	is_letter2(t_game *s, int i, int j, int bol)
{
	if (bol)
	{
		s->bat_x = j * 64;
		s->bat_y = i * 64;
		moving(s);
		ft_animate3(*s);
	}
	else
	{
		s->fire_x = j * 64;
		s->fire_y = i * 64;
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fireball, s->fire_x, s->fire_y);
		move_fire(s);
	}
}

void	up_down(t_game *s, int i, int j, int bol)
{
	s->mov++;
	if (bol)
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 0, 0);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 64, 0);
		print_count(s);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y);
		s->map1[i][j] = '0';
		s->pos_y -= 64;
		s->map1[i - 1][j] = 'P';
	}
	else
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 0, 0);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 64, 0);
		print_count(s);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y);
		s->map1[i][j] = '0';
		s->pos_y += 64;
		s->map1[i + 1][j] = 'P';
	}
}

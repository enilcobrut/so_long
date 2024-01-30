/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:14:14 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:13:20 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <math.h>
#include <time.h>

void	movebat_up(t_game *s)
{
	int	i;
	int	j;

	i = s->bat_y / 64;
	j = s->bat_x / 64;
	if (s->map1[i - 1][j] == 'P')
	{
		ft_printf(1, "\033[31mPERDU NULLOS!\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	else if (s->map1[i - 1][j] != 'C' && s->map1[i - 1][j] != 'E'
		&& s->map1[i - 1][j] != '1' && s->map1[i - 1][j] != 'Q')
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->bat_x, s->bat_y);
		s->map1[i][j] = '0';
		s->bat_y -= 64;
		s->map1[i - 1][j] = 'Q';
	}
}

void	movebat_down(t_game *s)
{
	int	i;
	int	j;

	i = s->bat_y / 64;
	j = s->bat_x / 64;
	if (s->map1[i + 1][j] == 'P')
	{
		ft_printf(1, "\033[31mPERDU NULLOS!\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	else if (s->map1[i + 1][j] != 'E' && s->map1[i + 1][j] != 'C'
		&& s->map1[i + 1][j] != '1' && s->map1[i + 1][j] != 'Q')
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->bat_x, s->bat_y);
		s->map1[i][j] = '0';
		s->bat_y += 64;
		s->map1[i + 1][j] = 'Q';
	}
}

void	movebat_left(t_game *s)
{
	int	i;
	int	j;

	i = s->bat_y / 64;
	j = s->bat_x / 64;
	dir_left(s, 0);
	if (s->map1[i][j - 1] == 'P')
	{
		ft_printf(1, "\033[31mPERDU NULLOS!\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	else if (s->map1[i][j - 1] != 'E' && s->map1[i][j - 1] != 'C'
		&& s->map1[i][j - 1] != '1' && s->map1[i][j - 1] != 'Q')
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->bat_x, s->bat_y);
		s->map1[i][j] = '0';
		s->bat_x -= 64;
		s->map1[i][j - 1] = 'Q';
	}
}

void	movebat_right(t_game *s)
{
	int	i;
	int	j;

	i = s->bat_y / 64;
	j = s->bat_x / 64;
	dir_right(s, 0);
	if (s->map1[i][j + 1] == 'P')
	{
		ft_printf(1, "\033[31mPERDU NULLOS!\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	else if (s->map1[i][j + 1] != 'E' && s->map1[i][j + 1] != 'C'
		&& s->map1[i][j + 1] != '1' && s->map1[i][j + 1] != 'Q')
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->bat_x, s->bat_y);
		s->map1[i][j] = '0';
		s->bat_x += 64;
		s->map1[i][j + 1] = 'Q';
	}
}

void	moving(t_game *s)
{
	static int	i = 0;
	static int	loop = 0;

	i = rand() % 4 + 1;
	if (++loop == 5 * s->nb_bat)
	{
		if (i == 1)
			movebat_up(s);
		else if (i == 2)
			movebat_down(s);
		else if (i == 3)
			movebat_left(s);
		else if (i == 4)
			movebat_right(s);
		loop = 0;
	}
}

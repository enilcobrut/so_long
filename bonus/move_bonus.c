/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:51 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:12:53 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdio.h>

int	ft_close(int keycode, t_game *start)
{
	if (keycode == 0)
		move_left(start);
	else if (keycode == 13)
		move_up(start);
	else if (keycode == 1)
		move_down(start);
	else if (keycode == 2)
		move_right(start);
	else if (keycode == 49)
		pushfire(start);
	if (keycode == 53)
	{
		mlx_destroy_window(start->mlx, start->mlx_win);
		exit(0);
	}
	return (0);
}

void	move_left(t_game *s)
{
	int	i;
	int	j;

	i = s->pos_y / 64;
	j = s->pos_x / 64;
	s->dir = 1;
	dir_left(s, 1);
	if (s->map1[i][j - 1] == 'C')
		if_collect(s, i, j, 0);
	if (s->map1[i][j - 1] == 'E' && s->nb_collec == s->max)
	{
		print_final();
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	else if (s->map1[i][j - 1] == 'Q')
	{
		ft_printf(1, "\033[31mGAME OVER\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i][j - 1] != '1' && s->map1[i][j - 1] != 'E')
		left_right(s, i, j, 1);
}

void	move_right(t_game *s)
{
	int	i;
	int	j;

	i = s->pos_y / 64;
	j = s->pos_x / 64;
	s->dir = 0;
	dir_right(s, 1);
	if (s->map1[i][j + 1] == 'C')
		if_collect(s, i, j, 1);
	if (s->map1[i][j + 1] == 'E' && s->nb_collec == s->max)
	{
		print_final();
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i][j + 1] == 'Q')
	{
		ft_printf(1, "\033[31mGAME OVER\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i][j + 1] != '1' && s->map1[i][j + 1] != 'E')
		left_right(s, i, j, 0);
}

void	move_up(t_game *s)
{
	int	i;
	int	j;

	i = s->pos_y / 64;
	j = s->pos_x / 64;
	if (s->map1[i - 1][j] == 'C')
		is_collect2(s, i, j, 1);
	if (s->map1[i - 1][j] == 'E' && s->nb_collec == s->max)
	{
		print_final();
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i - 1][j] == 'Q')
	{
		ft_printf(1, "\033[31mGAME OVER\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i - 1][j] != '1' && s->map1[i - 1][j] != 'E')
		up_down(s, i, j, 1);
}

void	move_down(t_game *s)
{
	int	i;
	int	j;

	i = s->pos_y / 64;
	j = s->pos_x / 64;
	if (s->map1[i + 1][j] == 'C')
		is_collect2(s, i, j, 0);
	if (s->map1[i + 1][j] == 'E' && s->nb_collec == s->max)
	{
		print_final();
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i + 1][j] == 'Q')
	{
		ft_printf(1, "\033[31mGAME OVER\n");
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i + 1][j] != '1' && s->map1[i + 1][j] != 'E')
		up_down(s, i, j, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:51 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:13:23 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(int keycode, t_game *start)
{
	mlx_loop_hook(start->mlx, render_next_frame, (void *)start);
	if (keycode == 0)
		move_left(start);
	else if (keycode == 13)
		move_up(start);
	else if (keycode == 1)
		move_down(start);
	else if (keycode == 2)
		move_right(start);
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
	dir_left(s);
	if (s->map1[i][j - 1] == 'C')
		if_collect(s, i, j, 0);
	if (s->map1[i][j - 1] == 'E' && s->nb_collec == s->max)
	{
		print_final();
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
	dir_right(s);
	if (s->map1[i][j + 1] == 'C')
		if_collect(s, i, j, 1);
	if (s->map1[i][j + 1] == 'E' && s->nb_collec == s->max)
	{
		print_final();
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
		if_collect(s, i, j, 2);
	if (s->map1[i - 1][j] == 'E' && s->nb_collec == s->max)
	{
		print_final();
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i - 1][j] != '1' && s->map1[i - 1][j] != 'E')
	{
		s->mov++;
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 0, 0);
		print_count(s);
		ft_printf(1, "\033[34mmove=%d\n", s->mov);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y);
		s->map1[i][j] = '0';
		s->pos_y -= 64;
		s->map1[i - 1][j] = 'P';
	}
}

void	move_down(t_game *s)
{
	int	i;
	int	j;

	i = s->pos_y / 64;
	j = s->pos_x / 64;
	if (s->map1[i + 1][j] == 'C')
		if_collect(s, i, j, 3);
	if (s->map1[i + 1][j] == 'E' && s->nb_collec == s->max)
	{
		print_final();
		mlx_destroy_window(s->mlx, s->mlx_win);
		exit(0);
	}
	if (s->map1[i + 1][j] != '1' && s->map1[i + 1][j] != 'E')
	{
		s->mov++;
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 0, 0);
		print_count(s);
		ft_printf(1, "\033[34mmove=%d\n", s->mov);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y);
		s->map1[i][j] = '0';
		s->pos_y += 64;
		s->map1[i + 1][j] = 'P';
	}
}

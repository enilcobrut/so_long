/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:47:40 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/28 17:46:05 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	dir_left(t_game	*s)
{
	s->krokmou[0] = xpm_to_img(*s, s->rel_haut1);
	s->krokmou[1] = xpm_to_img(*s, s->rel_krokmou1);
	s->krokmou[2] = xpm_to_img(*s, s->rel_bas1);
}

void	dir_right(t_game *s)
{
	s->krokmou[0] = xpm_to_img(*s, s->rel_haut);
	s->krokmou[1] = xpm_to_img(*s, s->rel_krokmou);
	s->krokmou[2] = xpm_to_img(*s, s->rel_bas);
}

void	if_collect(t_game *s, int i, int j, int index)
{
	s->nb_collec++;
	if (index == 0)
	{
		s->map1[i][j - 1] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->fond,
			s->pos_x - 64, s->pos_y);
	}
	else if (index == 1)
	{
		s->map1[i][j + 1] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->fond,
			s->pos_x + 64, s->pos_y);
	}
	else if (index == 2)
	{
		s->map1[i - 1][j] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y - 64);
	}
	else if (index == 3)
	{
		s->map1[i + 1][j] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y + 64);
	}
}

void	left_right(t_game *s, int i, int j, int bol)
{
	s->mov++;
	if (bol)
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 0, 0);
		print_count(s);
		ft_printf(1, "\033[34mmove=%d\n", s->mov);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y);
		s->map1[i][j] = '0';
		s->pos_x -= 64;
		s->map1[i][j - 1] = 'P';
	}
	else
	{
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->crystal, 0, 0);
		print_count(s);
		ft_printf(1, "\033[34mmove=%d\n", s->mov);
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y);
		s->map1[i][j] = '0';
		s->pos_x += 64;
		s->map1[i][j + 1] = 'P';
	}
}

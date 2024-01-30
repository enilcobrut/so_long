/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:45:36 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/25 13:25:57 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_animate2(t_game s)
{
	static int	loop = 0;

	loop++;
	if (loop == 0)
		mlx_put_image_to_window(s.mlx, s.mlx_win, s.furie[0], s.end_x, s.end_y);
	else if (loop >= 5 && loop <= 10)
		print_img(s, s.furie[1], s.end_x, s.end_y);
	else if (loop > 10 && loop <= 15)
		print_img(s, s.furie[2], s.end_x, s.end_y);
	else if (loop > 15 && loop <= 20)
		print_img(s, s.furie[1], s.end_x, s.end_y);
	else if (loop > 20 && loop <= 25)
		print_img(s, s.furie[0], s.end_x, s.end_y);
	else if (loop > 25)
		loop = 0;
	return (1);
}

int	ft_animate(t_game s)
{
	static int	loop = 0;

	loop++;
	if (loop == 0)
		mlx_put_image_to_window(s.mlx, s.mlx_win,
			s.krokmou[0], s.pos_x, s.pos_y);
	else if (loop >= 5 && loop <= 10)
		print_img(s, s.krokmou[1], s.pos_x, s.pos_y);
	else if (loop > 10 && loop <= 15)
		print_img(s, s.krokmou[2], s.pos_x, s.pos_y);
	else if (loop > 15 && loop <= 20)
		print_img(s, s.krokmou[1], s.pos_x, s.pos_y);
	else if (loop > 20 && loop <= 25)
		print_img(s, s.krokmou[0], s.pos_x, s.pos_y);
	else if (loop > 25)
		loop = 0;
	return (1);
}

int	render_next_frame(t_game *s)
{
	ft_animate(*s);
	ft_animate2(*s);
	return (1);
}

void	init_sprites(t_game *s)
{
	s->furie[0] = xpm_to_img(*s, s->rel_up);
	s->furie[1] = xpm_to_img(*s, s->rel_eclairfurie);
	s->furie[2] = xpm_to_img(*s, s->rel_down);
	s->krokmou[0] = xpm_to_img(*s, s->rel_haut);
	s->krokmou[1] = xpm_to_img(*s, s->rel_krokmou);
	s->krokmou[2] = xpm_to_img(*s, s->rel_bas);
}

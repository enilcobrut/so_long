/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:50:02 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/28 17:16:34 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_animate2(t_game s)
{
	static int	loop = 0;

	loop++;
	if (loop == 0 && loop < 5)
		mlx_put_image_to_window(s.mlx, s.mlx_win, s.furie[0], s.end_x, s.end_y);
	else if (loop >= (5 * s.nb_e) && loop <= (s.nb_e * 10))
		print_img(s, s.furie[1], s.end_x, s.end_y);
	else if (loop > (10 * s.nb_e) && loop <= (15 * s.nb_e))
		print_img(s, s.furie[2], s.end_x, s.end_y);
	else if (loop > (15 * s.nb_e) && loop <= (20 * s.nb_e))
		print_img(s, s.furie[1], s.end_x, s.end_y);
	else if (loop > (20 * s.nb_e) && loop <= (23 * s.nb_e))
		print_img(s, s.furie[0], s.end_x, s.end_y);
	else if (loop > (23 * s.nb_e))
		loop = 0;
	return (1);
}

int	ft_animate4(t_game s)
{
	static int	loop = 0;

	loop++;
	if (loop == 0 && loop < 5)
		mlx_put_image_to_window(s.mlx, s.mlx_win, s.collect[0], s.x, s.y);
	else if (loop >= (5 * s.nb_c) && loop <= (s.nb_c * 10))
		print_img(s, s.collect[1], s.x, s.y);
	else if (loop > (10 * s.nb_c) && loop <= (15 * s.nb_c))
		print_img(s, s.collect[2], s.x, s.y);
	else if (loop > (15 * s.nb_c) && loop <= (20 * s.nb_c))
		print_img(s, s.collect[1], s.x, s.y);
	else if (loop > (20 * s.nb_c) && loop <= (23 * s.nb_c))
		print_img(s, s.collect[0], s.x, s.y);
	else if (loop > (23 * s.nb_c))
		loop = 0;
	return (1);
}

int	ft_animate3(t_game s)
{
	static int	loop = 0;

	loop++;
	if (loop == 0 && loop < 5)
		mlx_put_image_to_window(s.mlx, s.mlx_win, s.bat[0], s.bat_x, s.bat_y);
	else if (loop >= (5 * s.nb_bat) && loop <= (10 * s.nb_bat))
		print_img(s, s.bat[1], s.bat_x, s.bat_y);
	else if (loop > (10 * s.nb_bat) && loop <= (15 * s.nb_bat))
		print_img(s, s.bat[2], s.bat_x, s.bat_y);
	else if (loop > (15 * s.nb_bat) && loop <= (20 * s.nb_bat))
		print_img(s, s.bat[1], s.bat_x, s.bat_y);
	else if (loop > (20 * s.nb_bat) && loop <= (25 * s.nb_bat))
		print_img(s, s.bat[0], s.bat_x, s.bat_y);
	else if (loop > (25 * s.nb_bat))
		loop = 0;
	return (1);
}

int	ft_animate(t_game s)
{
	static int	loop = 0;

	loop++;
	if (loop == 0 && loop < 5)
		mlx_put_image_to_window(s.mlx, s.mlx_win,
			s.krokmou[0], s.pos_x, s.pos_y);
	else if (loop >= 5 && loop <= 10)
		print_img(s, s.krokmou[1], s.pos_x, s.pos_y);
	else if (loop > 10 && loop <= 15)
		print_img(s, s.krokmou[2], s.pos_x, s.pos_y);
	else if (loop > 15 && loop <= 20)
		print_img(s, s.krokmou[1], s.pos_x, s.pos_y);
	else if (loop > 20 && loop <= 23)
		print_img(s, s.krokmou[0], s.pos_x, s.pos_y);
	else if (loop > 23)
		loop = 0;
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
	s->bat[0] = xpm_to_img(*s, s->rel_bat_up);
	s->bat[1] = xpm_to_img(*s, s->rel_bat);
	s->bat[2] = xpm_to_img(*s, s->rel_bat_down);
	s->fireball = xpm_to_img(*s, s->rel_fireball);
	s->collect[0] = xpm_to_img(*s, s->rel_collect1);
	s->collect[1] = xpm_to_img(*s, s->rel_collect);
	s->collect[2] = xpm_to_img(*s, s->rel_collect2);
}

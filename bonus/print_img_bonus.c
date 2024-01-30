/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:59:49 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/28 21:27:44 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_img(t_game s, void *img, int x, int y)
{
	mlx_put_image_to_window(s.mlx, s.mlx_win, s.fond, x, y);
	mlx_put_image_to_window(s.mlx, s.mlx_win, img, x, y);
}

void	init_img(t_game *start)
{
	start->rel_collect = "./img/collect.xpm";
	start->rel_haut = "./img/haut.xpm";
	start->rel_bas = "./img/bas.xpm";
	start->rel_haut1 = "./img/haut2.xpm";
	start->rel_bas1 = "./img/bas2.xpm";
	start->rel_up = "./img/light_up.xpm";
	start->rel_down = "./img/light_down.xpm";
	start->rel_bat_down = "./img/bat1_down.xpm";
	start->rel_bat = "./img/bat1.xpm";
	start->rel_bat_up = "./img/bat1_up.xpm";
	start->rel_batdownleft = "./img/batdown.xpm";
	start->rel_batleft = "./img/batleft.xpm";
	start->rel_batupleft = "./img/batupleft.xpm";
	start->rel_fireball = "./img/fireball.xpm";
	start->rel_leftfireball = "./img/leftfireball.xpm";
	start->rel_collect1 = "./img/collect1.xpm";
	start->rel_collect2 = "./img/collect2.xpm";
}

void	is_collect2(t_game *s, int i, int j, int bol)
{
	s->nb_collec++;
	s->nb_c--;
	if (bol)
	{
		s->map1[i - 1][j] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y - 64);
	}
	else
	{
		s->map1[i + 1][j] = '0';
		mlx_put_image_to_window(s->mlx, s->mlx_win,
			s->fond, s->pos_x, s->pos_y + 64);
	}
}

void	*xpm_to_img(t_game game, char *str)
{
	int		img_width;
	int		img_height;
	void	*result;

	result = mlx_xpm_file_to_image(game.mlx, str, &img_width, &img_height);
	if (!result)
		error("problem with xpm path");
	return (result);
}

void	print_final(void)
{
	ft_printf(1, "\033[35m♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥\n");
	ft_printf(1, "\033[35m♥FELICITATION VOUS AVEZ RAMENEE TOUS LES BEBES♥\n");
	ft_printf(1, "\033[35m♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥☼♥\n");
}

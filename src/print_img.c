/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:59:49 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/28 21:06:56 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_img(t_game s, void *img, int x, int y)
{
	mlx_put_image_to_window(s.mlx, s.mlx_win, s.fond, x, y);
	mlx_put_image_to_window(s.mlx, s.mlx_win, img, x, y);
}

void	print_final(void)
{
	ft_printf(1, "\033[35m╔═════════════════════════════════════════════╗\n");
	ft_printf(1, "\033[35m║FELICITATION VOUS AVEZ RAMENEE TOUS LES BEBES║\n");
	ft_printf(1, "\033[35m╚═════════════════════════════════════════════╝\n");
}

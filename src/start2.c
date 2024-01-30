/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:58:12 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:13:06 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_count(t_game *s)
{
	char	*count;

	count = ft_itoa(s->mov);
	mlx_string_put(s->mlx, s->mlx_win, 30, 30, 0x00000FF00, count);
	free(count);
}

void	display_map(t_game *game, t_map *map)
{
	fond(game, map);
	mur(game, map);
}

int	ft_close2(t_game *s)
{
	mlx_destroy_window(s->mlx, s->mlx_win);
	exit(0);
}

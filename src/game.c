/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:09:14 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/25 13:26:38 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	perso(t_game *s, t_map *map)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		len = ft_strlen(map->m[i]);
		while (j < len)
		{
			if (map->m[i][j] == 'P')
			{
				s->pos_x = j * 64;
				s->pos_y = i * 64;
				mlx_put_image_to_window(s->mlx, s->mlx_win,
					s->krokmou[1], s->pos_x, s->pos_y);
			}
			j++;
		}
		i++;
	}
}

void	perso2(t_game *s, t_map *map)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		len = ft_strlen(map->m[i]);
		while (j < len)
		{
			if (map->m[i][j] == 'E')
			{
				s->end_x = j * 64;
				s->end_y = i * 64;
				mlx_put_image_to_window(s->mlx, s->mlx_win,
					s->furie[1], s->end_x, s->end_y);
			}
			j++;
		}
		i++;
	}
}

void	collect(t_game *s, t_map *map)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	s->x = 0;
	s->y = 0;
	while (i < map->nb_line)
	{
		j = 0;
		len = ft_strlen(map->m[i]);
		while (j < len)
		{
			if (map->m[i][j] == 'C')
			{
				s->max++;
				s->x = j * 64;
				s->y = i * 64;
				mlx_put_image_to_window(s->mlx, s->mlx_win,
					s->collect, s->x, s->y);
			}
			j++;
		}
		i++;
	}
}

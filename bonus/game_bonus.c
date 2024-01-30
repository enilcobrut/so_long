/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:09:14 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/28 16:49:04 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_nb_e(t_map *map)
{
	int	i;
	int	len;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (i < map->nb_line)
	{
		j = 0;
		len = ft_strlen(map->m[i]);
		while (j < len)
		{
			if (map->m[i][j] == 'E')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	get_collect(t_map *map, t_game *s)
{
	int	i;
	int	len;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		len = ft_strlen(map->m[i]);
		while (j < len)
		{
			if (map->m[i][j] == 'C')
			{
				s->max++;
				res++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int	patrol(t_game *s)
{
	s->i = -1;
	while (++s->i < s->nb_line1)
	{
		s->j = -1;
		s->len = ft_strlen(s->map1[s->i]);
		while (++s->j < s->len)
		{
			if (s->map1[s->i][s->j] == 'P')
				is_letter(s, s->i, s->j, 1);
			else if (s->map1[s->i][s->j] == 'E')
				is_letter(s, s->i, s->j, 2);
			else if (s->map1[s->i][s->j] == 'C')
				is_letter(s, s->i, s->j, 3);
			else if (s->map1[s->i][s->j] == 'Q')
				is_letter2(s, s->i, s->j, 1);
			else if (s->map1[s->i][s->j] == '0')
				mlx_put_image_to_window(s->mlx, s->mlx_win,
					s->fond, s->j * 64, s->i * 64);
			else if (s->map1[s->i][s->j] == '.')
				is_letter2(s, s->i, s->j, 0);
		}
	}
	return (1);
}

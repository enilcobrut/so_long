/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:50:02 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:56:15 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_game	starte(t_map map, char *str)
{
	t_game	s;

	s.y_max = map.nb_line;
	s.x_max = ft_strlen(map.m[0]) - 1;
	s.mlx = mlx_init();
	s.mlx_win = mlx_new_window(s.mlx, s.x_max * 64, s.y_max * 64, "so_long");
	s.x = 0;
	s.y = 0;
	s.pos_x = 0;
	s.pos_y = 0;
	s.rel_krokmou = "./img/krokmou.xpm";
	s.rel_krokmou1 = "./img/krokmou2.xpm";
	s.rel_crystal = "./img/crystal.xpm";
	s.rel_fond = "./img/fond.xpm";
	s.rel_eclairfurie = "./img/eclairfurie.xpm";
	s.crystal = xpm_to_img(s, s.rel_crystal);
	s.fond = xpm_to_img(s, s.rel_fond);
	s.map1 = fill_map(str);
	s.end_x = 0;
	s.end_y = 0;
	return (s);
}

void	fond(t_game *s, t_map *map)
{
	int	i;
	int	len;
	int	j;

	j = 0;
	i = 0;
	while (i < map->nb_line)
	{
		len = ft_strlen(map->m[i]);
		j = 0;
		s->x = 0;
		if (i == map->nb_line - 1)
			len = len + 1;
		while (j < len)
		{	
			mlx_put_image_to_window(s->mlx, s->mlx_win, s->fond, s->x, s->y);
			s->x += 64;
			j++;
		}
		s->y += 64;
		i++;
	}
}

void	mur(t_game *s, t_map *map)
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
			if (map->m[i][j] == '1')
			{
				s->x = j * 64;
				s->y = i * 64;
				mlx_put_image_to_window(s->mlx, s->mlx_win,
					s->crystal, s->x, s->y);
			}
			j++;
		}
		i++;
	}
}

int	get_nb_bat(t_map *map)
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
			if (map->m[i][j] == 'Q')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

void	start(t_map map, char *str)
{
	t_game	start;

	start = starte(map, str);
	start.nb_line1 = get_nb_line(str);
	start.dir = 0;
	start.len = 0;
	start.i = 0;
	start.j = 0;
	start.tp = 0;
	init_img(&start);
	init_sprites(&start);
	init_value(&start, &map);
	display_map(&start, &map);
	start.nb_c = get_collect(&map, &start);
	mlx_hook(start.mlx_win, 2, 1L << 0, ft_close, &start);
	mlx_loop_hook(start.mlx, &patrol, (void *)&start);
	mlx_hook(start.mlx_win, 17, 1L << 0, ft_close2, &start);
	mlx_loop(start.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:14:03 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 17:51:18 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

t_map	*map1(void)
{
	t_map	*result;

	result = malloc(sizeof(t_map));
	result->e = 0;
	result->p = 0;
	result->c = 0;
	result->len = 0;
	return (result);
}

int	get_nb_line(char *str)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error("error file");
	line = get_next_line(fd);
	if (!line)
		error("file is empty");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	if (fd == -1)
		error("pb with fd");
	return (i);
}

void	fk_norme(char *line, t_map *map, int fd)
{
	free(line);
	line = get_next_line(fd);
	parce_first(line, map, 1);
	free(line);
	if (map->e <= 0 || map->p != 1 || map->c <= 0)
		error("Miss perso or sortie");
	free(map);
}

char	**fill_map(char *str)
{
	int		len;
	char	**res;
	int		fd;
	int		i;
	int		tplen;

	i = 0;
	len = get_nb_line(str);
	tplen = len;
	res = malloc(sizeof(char *) * (len + 1));
	fd = open(str, O_RDONLY);
	while (len)
	{
		res[i] = get_next_line(fd);
		i++;
		len--;
	}
	close(fd);
	if (fd == -1)
		error("pb with fd");
	return (res);
}

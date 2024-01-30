/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:55:30 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:42:46 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_format(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[len - 4] == '.' && str[len - 3] == 'b' && str[len - 2] == 'e'
			&& str[len - 1] == 'r' && str[len - 5] != '/' && len > 4)
			return (1);
		i++;
	}
	return (0);
}

void	parce_first(char *str, t_map *map, int bol)
{
	int	i;
	int	len1;

	(void)map;
	len1 = ft_strlen(str);
	if (bol)
	{
		if (map->len - 1 != len1)
			error("FK");
	}
	i = 0;
	while (i < len1 && str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1')
			error("wrong map");
		i++;
	}
}

void	parce_line( char *str, t_map *map)
{
	int	i;
	int	len1;

	if (!str)
		error("file is empty");
	len1 = ft_strlen(str);
	if (map->len != len1)
		error("wrong map size");
	i = 0;
	while (i < len1 && str[i] != '\n')
	{
		if (str[i] == 'E')
			map->e++;
		else if (str[i] == 'P')
			map->p++;
		else if (str[i] == 'C')
			map->c++;
		if (str[0] != '1' || str[len1 - 2] != '1')
			error("wrong2 map");
		else if (str[i] != '1' && str[i] != '0' && str[i] != 'E'
			&& str[i] != 'P' && str[i] != 'C' && str[i] != 'Q')
			error("wrong3 map");
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:40:15 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/29 18:12:40 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	start_map(char *str)
{
	t_map	res;

	res.nb_line = get_nb_line(str);
	res.m = fill_map(str);
	return (res);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		if (!(check_format(av[1])))
			error("wrong file format");
		else
		{
			parce_error(av[1]);
			map = start_map(av[1]);
			start(map, av[1]);
		}
	}
	else
		error("wrong number of arguments");
}

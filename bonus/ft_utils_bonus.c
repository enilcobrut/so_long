/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:45:06 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/25 13:50:31 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error(char *str)
{
	ft_printf(2, "Error\n%s\n", str);
	exit(1);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	s = malloc(size * count);
	if (!s)
		return (s);
	i = -1;
	while (++i < count * size)
		s[i] = 0;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	char	c1;
	int		i;
	int		len;

	s1 = (char *)s;
	c1 = (char)c;
	len = ft_strlen(s1);
	i = -1;
	if (!s1)
		return (NULL);
	while (++i < len)
		if (s1[i] == c1)
			return (&s1[i]);
	if (s1[i] == c1)
		return (&s1[i]);
	return (NULL);
}

void	ft_freedouble(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = 0;
			i++;
		}
		free(ptr);
		ptr = 0;
	}
}

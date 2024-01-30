/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 08:15:27 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/25 13:23:00 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	int			i;
	int			j;

	if (!s1 || !s2)
		return (0);
	s3 = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!s3)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i++] = s2[j];
	s3[i] = 0;
	return (s3);
}

char	*ft_nextline(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(save) - i + 1), 1);
	j = 0;
	while (save[++i])
		line[j++] = save[i];
	free(save);
	return (line);
}

char	*ft_currentline(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	i = -1;
	while (save[++i] && save[i] != '\n')
		line[i] = save[i];
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *save)
{
	char	*buffer;
	int		nbbytes;
	char	*tp;

	if (!save)
		save = ft_calloc(1, 1);
	buffer = ft_calloc(2, 1);
	nbbytes = 1;
	while (nbbytes > 0)
	{
		nbbytes = read(fd, buffer, 1);
		buffer[nbbytes] = 0;
		tp = ft_strjoin(save, buffer);
		free(save);
		save = tp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_currentline(save);
	save = ft_nextline(save);
	return (line);
}

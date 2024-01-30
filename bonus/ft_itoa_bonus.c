/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:48:08 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/25 13:50:18 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	intlen(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	solve(long long nb, char *r, int i)
{
	while (nb > 0)
	{
		r[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, len);
	return (s2);
}

char	*ft_itoa(int n)
{
	char		*r;
	int			i;
	long long	nb;

	nb = n;
	i = intlen(nb);
	if (n == 0)
		return (ft_strdup("0"));
	r = malloc(sizeof(char) * (i + 1));
	if (!r)
		return (NULL);
	r[i--] = '\0';
	if (nb < 0)
	{
		r[0] = '-';
		nb = -nb;
	}
	solve(nb, r, i);
	return (r);
}

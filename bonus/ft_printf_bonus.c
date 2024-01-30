/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjunker <cjunker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 07:48:57 by cjunker           #+#    #+#             */
/*   Updated: 2022/08/25 13:50:28 by cjunker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdarg.h>
#include <unistd.h>

static int	printchar(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int	printstr(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

static int	printnbr(int n, int fd)
{
	if (n == -2147483648)
		return (printstr("-2147483648", fd));
	else if (n < 0)
		return (printchar('-', fd) + printnbr(-n, fd));
	else if (n > 9)
		return (printnbr(n / 10, fd) + printnbr(n % 10, fd));
	else
		return (printchar(n + '0', fd));
}

static int	checkformat(va_list param, char c, int fd)
{
	int	nbchars;

	nbchars = 0;
	if (c == 'c')
		nbchars += printchar(va_arg(param, int), fd);
	else if (c == 's')
		nbchars += printstr(va_arg(param, char *), fd);
	else if (c == 'd' || c == 'i')
		nbchars += printnbr(va_arg(param, int), fd);
	return (nbchars);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	param;
	int		nbchars;
	int		i;

	i = 0;
	va_start(param, str);
	nbchars = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			nbchars += checkformat(param, str[i + 1], fd);
			i++;
		}
		else
			nbchars += printchar(str[i], fd);
		i++;
	}
	va_end(param);
	return (nbchars);
}

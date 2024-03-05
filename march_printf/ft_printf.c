/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:04:03 by sepatez           #+#    #+#             */
/*   Updated: 2024/03/05 19:00:08 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_tolower(char *c)
{
	return (*c);
}

char	ft_toupper(char *c)
{
	if (*c >= 97 && *c <= 122)
		return (*c - 32);
	return (*c);
}

int	ft_dispatch(const char *format, va_list args)
{
	if (*format == '%')
	{
		write(1, format++, 1);
		return (1);
	}
	else if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'p')
		return (le_teton(va_arg(args, void *)));
	else if (*format == 'd')
		return (ft_putint(va_arg(args, int)));
	else if (*format == 'i')
		return (ft_putint(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (puthexa(va_arg(args, int), ft_tolower));
	else if (*format == 'X')
		return (puthexa(va_arg(args, int), ft_toupper));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	register int	i;
	int				temp;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			temp = ft_dispatch(++format, args);
			if (temp == -1)
			{
				va_end(args);
				return (-1);
			}
			format++;
			i += temp;
		}
		while (*format && *format != '%')
			i += ft_putchar(*format++);
	}
	va_end(args);
	return (i);
}

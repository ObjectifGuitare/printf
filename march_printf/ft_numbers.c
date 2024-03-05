/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:34:24 by sepatez           #+#    #+#             */
/*   Updated: 2023/04/26 09:12:31 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	le_teton(void *p)
{
	unsigned long long	address;

	write(1, "0x", 2);
	address = (unsigned long long) p;
	return (put_ulong_hexa(address) + 2);
}

int	put_ulong_hexa(unsigned long long n)
{
	int		i;
	char	*hexa_set;

	hexa_set = "0123456789abcdef";
	i = 0;
	if (n > 15)
		i += put_ulong_hexa(n / 16);
	write(1, hexa_set + (n % 16), 1);
	i++;
	return (i);
}

int	puthexa(unsigned int n, char (*f)(char *))
{
	int		i;
	char	*hexa_set;

	hexa_set = "0123456789abcdef";
	i = 0;
	if (n > 15)
		i += puthexa(n / 16, f);
	ft_putchar(f(hexa_set + (n % 16)));
	i++;
	return (i);
}

int	ft_putint(int n)
{
	long long	nb;
	int			i;

	i = 0;
	nb = (long long) n;
	if (nb < 0)
	{
		ft_putchar('-');
		i++;
		nb *= -1;
	}
	if (nb > 9)
		i += ft_putint(nb / 10);
	ft_putchar((nb % 10) + '0');
	return (++i);
}

int	ft_putuint(unsigned int u)
{
	unsigned long long	nb;
	int					i;

	i = 0;
	nb = (unsigned long long) u;
	if (nb < 0)
	{
		ft_putchar('-');
		i++;
		nb *= -1;
	}
	if (nb > 9)
		i += ft_putuint(nb / 10);
	ft_putchar((nb % 10) + '0');
	return (++i);
}

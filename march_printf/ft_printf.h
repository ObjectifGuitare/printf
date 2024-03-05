/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepatez <sepatez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:05:35 by sepatez           #+#    #+#             */
/*   Updated: 2023/04/26 09:43:51 by sepatez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_dispatch(const char *format, va_list args);
int		ft_putuint(unsigned int u);
int		ft_putint(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);
char	ft_tolower(char *c);
char	ft_toupper(char *c);
int		puthexa(unsigned int n, char (*f)(char *));
int		le_teton(void *p);
int		put_ulong_hexa(unsigned long long n);

#endif
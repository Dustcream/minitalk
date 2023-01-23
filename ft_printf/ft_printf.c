/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:29:29 by dmuller           #+#    #+#             */
/*   Updated: 2022/11/23 15:11:32 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print(va_list args, const char *format, int *count, int *i)
{
	if (format[*i] == '%')
		ft_putchar(format[*i], count);
	else if (format[*i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format[*i] == 'u')
		ft_putunbr(va_arg(args, unsigned int), count);
	else if (format[*i] == 'x')
		ft_puthex(va_arg(args, unsigned int), count);
	else if (format[*i] == 'X')
		ft_hex(va_arg(args, unsigned int), count);
	else if (format[*i] == 'p')
		ft_pointers(va_arg(args, void *), count);
	*i += 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		n;

	va_start(args, format);
	i = 0;
	count = 0;
	n = ft_strlen(format);
	while (format[i] && i < n)
	{
		if (format[i] != '%')
			ft_putchar(format[i++], &count);
		else if (i < n)
		{
			i++;
			ft_print(args, format, &count, &i);
		}
	}
	va_end (args);
	return (count);
}

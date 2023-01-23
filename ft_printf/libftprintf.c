/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:07 by dmuller           #+#    #+#             */
/*   Updated: 2022/11/23 11:30:10 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(int c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_puthex(unsigned long n, int *count)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, count);
		ft_puthex(n % 16, count);
	}
	else if (n < 10)
		ft_putchar(n + 48, count);
	else
		ft_putchar(n + 87, count);
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar(('-'), count);
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	ft_putchar(n % 10 + 48, count);
}

void	ft_pointers(void *p, int *count)
{
	ft_putstr("0x", count);
	ft_puthex((unsigned long long)p, count);
}

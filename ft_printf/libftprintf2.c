/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:17:11 by dmuller           #+#    #+#             */
/*   Updated: 2022/11/23 11:30:59 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hex(unsigned int n, int *count)
{
	if (n >= 16)
	{
		ft_hex(n / 16, count);
		ft_hex(n % 16, count);
	}
	else if (n < 10)
		ft_putchar(n + 48, count);
	else
		ft_putchar(n + 55, count);
}

void	ft_putstr(const char *str, int *count)
{
	int	i;

	if (!str)
		*count += write(1, "(null)", 6);
	else
	{
		i = 0;
		while (str[i])
			ft_putchar(str[i++], count);
	}
}

void	ft_putunbr(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunbr((n / 10), count);
		ft_putunbr((n % 10), count);
	}
	else
		ft_putchar((n + 48), count);
}

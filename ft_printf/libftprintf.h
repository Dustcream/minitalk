/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:32:58 by dmuller           #+#    #+#             */
/*   Updated: 2022/11/23 11:35:32 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

void	ft_print(va_list args, const char *format, int *count, int *i);
int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *count);
void	ft_puthex(unsigned long n, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(const char *str, int *count);
void	ft_hex(unsigned int n, int *count);
void	ft_pointers(void *p, int *count);
void	ft_putunbr(unsigned int n, int *count);
size_t	ft_strlen(const char *s);

#endif
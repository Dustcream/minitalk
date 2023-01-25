/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:27:11 by dmuller           #+#    #+#             */
/*   Updated: 2023/01/25 10:42:34 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "ft_printf/libftprintf.h"

void	sighandler(int sig)
{
	static int		bit;
	static int		c;

	if (sig == SIGUSR1)
		c = c | (1 << bit);
	if (++bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	if (ac != 1)
	{
		ft_printf("Too many arguments\n");
		return (0);
	}
	ft_printf("PID -> %d\n", pid);
	ft_printf("Waiting for a signal...\n");
	while (ac == 1)
	{
		signal(SIGUSR1, sighandler);
		signal(SIGUSR2, sighandler);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:24:13 by brunhenr          #+#    #+#             */
/*   Updated: 2024/05/21 12:09:56 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

int	g_var = 0;

void	signal_error(int signum)
{
	if (signum != SIGUSR1 && signum != SIGUSR2)
	{
		ft_printf("Error: unexpected signal %d\n", signum);
		exit(1);
	}
}

void	reset_to_zero(unsigned char *buffer, unsigned char *bit_count)
{
	*buffer = 0;
	*bit_count = 0;
}

void	handler(int signum, siginfo_t *info, void *context)
{
	unsigned char	buffer;
	unsigned char	bit_count;

	(void)context;
	signal_error(signum);
	bit_count = g_var & 0x000000FF;
	buffer = (g_var & 0x0000FF00) >> 8;
	if (signum == SIGUSR1)
		buffer = buffer << 1;
	else
		buffer = (buffer << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (buffer == 0)
		{
			write(1, "\n", 1);
			g_var = 0;
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		write(1, &buffer, 1);
		reset_to_zero(&buffer, &bit_count);
	}
	g_var = (buffer << 8) | bit_count;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("\
 __  __  _  __  _  _  _____  ____   _     __  __ \n\
|  \\/  || ||  \\| || ||_   _|/ () \\ | |__ |  |/  /\n\
|_|\\/|_||_||_|\\__||_|  |_| /__/\\__\\|____||__|\\__\\\n\
|b|o|n|u|s|\n\n\
New features:\n\
	The server sends back a signal to client.\n\
	Unicode characters support!\n\
\nPID %d\nNow waiting for messages... \n\n\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

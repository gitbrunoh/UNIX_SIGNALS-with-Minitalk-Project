/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:24:13 by brunhenr          #+#    #+#             */
/*   Updated: 2024/07/24 19:33:37 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdbool.h>
#include <sys/types.h>

int	g_var = 0;

void	len_alloc_mem(int sig, char **msg, bool *is_receiving_len, \
	unsigned char *bit_count)
{
	static size_t	len = 0;

	len = len >> 1;
	if (sig == SIGUSR2)
		len = len | 0x8000000000000000;
	if (*bit_count == 64)
	{
		//printf("len: %zu\n", len);
		*msg = malloc(len + 1);
		if (*msg == NULL)
		{
			ft_printf("error: malloc failed");
			exit(EXIT_FAILURE);
		}
		(*msg)[len] = '\0';
		*is_receiving_len = false;
		g_var = 0;
		*bit_count = 0;
	}
}

void	put_byte_in_msg(char **msg, unsigned char buffer, \
	pid_t pid, bool *is_receiving_len)
{
	static size_t	i = 0;

	(*msg)[i] = buffer;
	i++;
	if (buffer == '\0')
	{
		ft_printf("%s\n", *msg);
		free(*msg);
		*msg = NULL;
		i = 0;
		*is_receiving_len = true;
		kill(pid, SIGUSR1);
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	unsigned char	buffer;
	unsigned char	bit_count;
	static bool		is_receiving_len = true;
	static char		*msg = NULL;

	(void) context;
	bit_count = g_var & 0x000000FF;
	buffer = (g_var & 0x0000FF00) >> 8;
	bit_count++;
	if (is_receiving_len)
		len_alloc_mem(signum, &msg, &is_receiving_len, &bit_count);
	else
	{
		buffer = buffer >> 1;
		if (signum == SIGUSR2)
			buffer = buffer | 128;
		if (bit_count == 8)
		{
			put_byte_in_msg(&msg, buffer, info->si_pid, &is_receiving_len);
			bit_count = 0;
			buffer = 0;
		}
	}
	g_var = (buffer << 8) | bit_count;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	ft_printf("\
 __  __  _  __  _  _  _____  ____   _     __  __ \n\
|  \\/  || ||  \\| || ||_   _|/ () \\ | |__ |  |/  /\n\
|_|\\/|_||_||_|\\__||_|  |_| /__/\\__\\|____||__|\\__\\\n\
|b|o|n|u|s|\n\n\
New features:\n\
	The server sends back a signal to client.\n\
	Unicode characters support!\n\
\nPID %d\nNow waiting for messages... \n\n\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
	sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("error : Sigaction Error");
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}

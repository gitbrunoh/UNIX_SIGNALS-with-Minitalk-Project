/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:23:15 by brunhenr          #+#    #+#             */
/*   Updated: 2024/07/24 19:25:13 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define _POSIX_C_SOURCE 199309L
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <sys/types.h>
#include <errno.h>

void	error_handler(pid_t pid, int check_kill, char *str)
{
	if (pid < 1)
	{
		ft_printf("error: PID out of range for this program\n");
		exit(EXIT_FAILURE);
	}
	if (kill(pid, 0) == -1)
	{
		if (errno == ESRCH)
			ft_printf("error: this PID [%d] doesn't exist.\n", pid);
		else if (errno == EPERM)
			ft_printf("error: no permissions to send signal \
	to PID [%d].\n", pid);
		exit(EXIT_FAILURE);
	}
	else if (str == NULL || str[0] == '\0')
	{
		ft_printf("error: message is null or empty\n");
		exit(EXIT_FAILURE);
	}
	else if (check_kill == -1)
	{
		ft_printf("Error! Kill error using PID %d!\n", pid);
		exit(EXIT_FAILURE);
	}
}

void	send_message(int pid, unsigned char *str, size_t len)
{
	size_t	i;
	int		k;
	int		check_kill;

	i = 0;
	k = 0;
	check_kill = 0;
	while (i < len + 1)
	{
		k = 0;
		while (k < 8)
		{
			if (str[i] & 1)
				check_kill = kill(pid, SIGUSR2);
			else
				check_kill = kill(pid, SIGUSR1);
			if (check_kill == -1)
				error_handler(pid, check_kill, "a");
			str[i] = str[i] >> 1;
			usleep(600);
			k++;
		}
		i++;
	}
}

void	send_len(pid_t g_server_pid, size_t len)
{
	int	i;
	int	check_kill;

	i = 0;
	check_kill = 0;
	while (i < 64)
	{
		if (len & 1)
			check_kill = kill(g_server_pid, SIGUSR2);
		else
			check_kill = kill(g_server_pid, SIGUSR1);
		if (check_kill == -1)
			error_handler(g_server_pid, check_kill, "a");
		len = len >> 1;
		usleep(600);
		i++;
	}
}

int	main(int argc, char **argv)
{
	size_t				len;
	pid_t				pid;

	if (argc != 3)
	{
		ft_printf("Attention! The usage is: ./client [VALID PID] [MESSAGE]\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi (argv[1]);
	error_handler(pid, 0, argv[2]);
	len = ft_strlen(argv[2]);
	send_len(pid, len);
	send_message (pid, (unsigned char *)argv[2], len);
	return (EXIT_SUCCESS);
}

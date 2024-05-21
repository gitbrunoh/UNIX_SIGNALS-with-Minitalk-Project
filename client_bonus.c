/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:23:15 by brunhenr          #+#    #+#             */
/*   Updated: 2024/05/21 14:42:27 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <sys/types.h> // for pid_t
#include <errno.h> // for errno

pid_t	g_server_pid;

unsigned char	reverse_bits(unsigned char b)
{
	unsigned char	r;
	unsigned int	byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void	error_handler(pid_t pid, int check_kill, char *str)
{
	if (pid < 1)
	{
		ft_printf("error: PID out of range\n");
		exit(1);
	}
	else if (kill(pid, 0) == -1 && (errno == ESRCH || errno == EINVAL))
	{
		ft_printf("error: this PID [%d] doesn't exist or is invalid\n", pid);
		exit(1);
	}
	else if (str == NULL || str[0] == '\0')
	{
		ft_printf("error: message is null or empty\n");
		exit(1);
	}
	else if (check_kill == -1)
	{
		ft_printf("Error! Kill error using PID %d!\n", pid);
		exit(2);
	}
}

void	send_message(int pid, unsigned char *str)
{
	int	i;
	int	k;
	int	check_kill;

	i = 0;
	k = 0;
	check_kill = 0;
	while (str[i] != '\0')
	{
		str[i] = reverse_bits(str[i]);
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
			usleep(700);
			k++;
		}
		i++;
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;
	if ((info->si_pid == g_server_pid) && (signum == SIGUSR1))
		ft_printf("Server (PID %d): text received!\n", info->si_pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					k;

	if (argc != 3)
	{
		ft_printf("Attention! The usage is: ./client [VALID PID] [MESSAGE]\n");
		exit(1);
	}
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	g_server_pid = ft_atoi (argv[1]);
	error_handler(g_server_pid, 0, argv[2]);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		perror("Sigaction Error");
	send_message (g_server_pid, (unsigned char *)argv[2]);
	k = 0;
	while (k < 8)
	{
		kill(g_server_pid, SIGUSR1);
		k++;
		usleep(500);
	}
	return (0);
}

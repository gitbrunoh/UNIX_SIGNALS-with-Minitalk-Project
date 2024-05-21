/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:38:00 by brunhenr          #+#    #+#             */
/*   Updated: 2024/05/21 10:46:46 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include <sys/types.h> // for pid_t
#include <unistd.h>
#include <errno.h> // for errno

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

void	error_handler(pid_t pid, int check_kill)
{
	if (pid < 1)
	{
		ft_printf("error: PID out of range for this program\n");
		exit(1);
	}
	else if (kill(pid, 0) == -1 && (errno == ESRCH || errno == EINVAL))
	{
		ft_printf("error: this PID [%d] doesn't exist or is invalid\n", pid);
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
				error_handler(pid, check_kill);
			str[i] = str[i] >> 1;
			usleep(700);
			k++;
		}
		i++;
	}
}

void	send_end(int pid)
{
	int	k;

	k = 0;
	while (k < 8)
	{
		kill(pid, SIGUSR1);
		usleep(600);
		k++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Attention! The usage is: ./client [VALID PID] [MESSAGE]\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	error_handler(pid, 0);
	if (argv[2] == NULL || argv[2][0] == '\0')
	{
		ft_printf("error: message is null or empty\n");
		exit(1);
	}
	send_message (pid, (unsigned char *)argv[2]);
	send_end (pid);
	return (0);
}

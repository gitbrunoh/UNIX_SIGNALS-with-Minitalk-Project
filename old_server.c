/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:29:16 by brunhenr          #+#    #+#             */
/*   Updated: 2024/06/03 18:41:28 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

int	g_var = 0;

void	handler(int signum)
{
	unsigned char	buffer;
	unsigned char	bit_count;

	bit_count = g_var & 0x000000FF;
	buffer = (g_var & 0x0000FF00) >> 8;
	if (signum == SIGUSR1)
		buffer = buffer << 1;
	else if (signum == SIGUSR2)
		buffer = (buffer << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (buffer == 0)
		{
			write(1, "\n", 1);
			g_var = 0;
			return ;
		}
		write(1, &buffer, 1);
		buffer = 0;
		bit_count = 0;
	}
	g_var = (buffer << 8) | bit_count;
}

int	main(void)
{
	ft_printf("\n\
Bruno Lopes\n\
 __  __ _____ _   _ _____ _______       _      _  __\n\
|  \\/  |_   _| \\ | |_   _|__   __|/\\   | |    | |/ /\n\
| \\  / | | | |  \\| | | |    | |  /  \\  | |    | ' / \n\
| |\\/| | | | | . ` | | |    | | / /\\ \\ | |    |  <  \n\
| |  | |_| |_| |\\  |_| |_   | |/ ____ \\| |____| . \\ \n\
|_|  |_|_____|_| \\_|_____|  |_/_/    \\_\\______|_|\\_\\\n\
\nPID %d\nWaiting for messages! \n\n\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

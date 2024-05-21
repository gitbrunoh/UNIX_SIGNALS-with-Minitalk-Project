/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:00:43 by brunhenr          #+#    #+#             */
/*   Updated: 2024/05/21 14:50:24 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c == 32)
		return (1);
	else
		return (0);
}

long long int	ft_atoi(const char *nptr)
{
	long long int	n;
	int				s;

	s = 1;
	n = 0;
	while (is_space(*nptr) == 1)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			s = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	return (n * s);
}

/*int	main(void)
{
	char	c = '1';
	char	*str = "44444444444";
	long long n;

	n = ft_atoi(str);
	printf("%lld", n);
	//n = n + 1;
	//ft_putnbr_fd(n, 1);
	return (0);
}*/

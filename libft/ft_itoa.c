/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:56:49 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/11 13:57:50 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nbr_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	cpy_chars_to_mem(int size, int cut, int n, char *str)
{
	while (size > cut)
	{
		str[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	size_t	cut;

	cut = 0;
	size = get_nbr_size(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str[1] = '2';
		str[0] = '-';
		n = 147483648;
		cut = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		cut = 1;
		n = -n;
	}
	cpy_chars_to_mem(size, cut, n, str);
	str[size] = '\0';
	return (str);
}

/*int	main(void)
{
	int	n;

	n = -1560;
	ft_putstr_fd(ft_itoa(n), 1);
	return (0);
}*/	

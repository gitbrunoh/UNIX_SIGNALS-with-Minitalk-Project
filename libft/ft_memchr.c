/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:45:33 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/09 16:45:51 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	value = (unsigned char)value;
	while (num > 0)
	{
		if (*str == value)
		{
			return ((void *)str);
		}
		else
		{
			str++;
			num--;
		}
	}
	return (NULL);
}

/*int	main()
{
	char str[] = "Gilberto Gil";
	char c = 'e';
	ft_putstr_fd(ft_memchr(str, c, ft_strlen(str)), 1);
	ft_putchar_fd('\n', 1);
}*/

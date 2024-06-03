/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:58:47 by brunhenr          #+#    #+#             */
/*   Updated: 2024/06/03 21:34:06 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && (len < __SIZE_MAX__))
	{
		len++;
		str++;
	}
	return (len);
}

/*
int	main(void)
{
	int			len;
	const char	*str = "bruno";

	len = ft_strlen(str);
	printf("Tamanho da string: %d", len);
	return (0);
}
*/

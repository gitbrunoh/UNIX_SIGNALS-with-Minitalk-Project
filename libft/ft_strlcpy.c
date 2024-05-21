/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:01:29 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/18 17:10:26 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char	dest[5];
	char	src[] = "This is the source";
	printf("Retorno da ft com size = 5: %zu \n", ft_strlcpy(dest, src, 5));
	printf("Destination: %s \n", dest);
	printf("Source: %s \n", src);
	return (0);
}
*/

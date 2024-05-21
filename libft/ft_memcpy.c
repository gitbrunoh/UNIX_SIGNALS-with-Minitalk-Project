/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:51:46 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/09 16:52:03 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d_ptr;
	const char	*s_ptr;

	if (dest == NULL && src == NULL)
		return (dest);
	d_ptr = dest;
	s_ptr = src;
	while (n--)
	{
		*d_ptr++ = *s_ptr++;
	}
	return (dest);
}

/*int	main(void)
{
	char	src[6] = "bruno";
	char	dst[100] = "content";
	char	src2[6] = "bruno";
	char	dst2[100] = "content";

	ft_memcpy(dst, src, 3);
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dst);	
	memcpy(dst2, src2, 3);
	printf("Source: %s\n", src2);
	printf("Destination: %s\n", dst2);

	return (0);
}*/

/*Verificar a possível sobreposição dos espaços de memória
referentes aos ponteiros. Não há na função original.
	if (d_ptr <= s_ptr && d_ptr + n > s_ptr)
		return (NULL);*/

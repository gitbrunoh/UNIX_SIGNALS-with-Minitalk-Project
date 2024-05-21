/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:43:41 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/11 15:55:25 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*a;
	char		*b;

	if (dest == NULL && src == NULL)
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	a = (char *)src;
	b = (char *)dest;
	while (n--)
		b[n] = a[n];
	return (dest);
}

/*int	main(void)
{
	const char	*str = "This text will be copied";
	char	dest[100];

	printf("A string dest resultou em: %s \n", (char *)ft_memmove(dest, str, 8));
	printf("A string dest resultou em: %s", (char *)memmove(dest, str, 8));
	return (0);
}*/

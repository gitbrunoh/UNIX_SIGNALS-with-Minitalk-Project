/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:42:18 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/18 11:06:04 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] != '\0' && len > i)
	{
		while (big[i + j] == little[j] && (i + j) < len && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		else
			j = 0;
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	printf("result ft: %s\n", ft_strnstr("Clareou", "eo", 6));
	printf("result ft: %s\n", strnstr("Clareou", "eo", 6));
	return (0);
}
*/

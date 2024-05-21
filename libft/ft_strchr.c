/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:40:30 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/18 12:35:41 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

/*int	main(void)
{
	const char	*str = "teste";
	int	c = 'e';
	char	*result = ft_strchr(str, c);
	
	if (result != NULL)
		printf("O caractere %c foi encontrado na position %ld", c, result - str);
	else
		printf("%c not founded.", c);
	return (0);
}*/

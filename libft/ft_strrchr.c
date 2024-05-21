/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:56:14 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/18 12:57:31 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != (char)c)
	{
		if (i < 0)
			return (NULL);
		i--;
	}
	return ((char *)&s[i]);
}

/*int	main(void)
{
	const char	*str = "aeiou aeiou";
	char	c = 'i';
	char	*result = ft_strrchr(str, c);
	
	if ( result != NULL)
	{
		printf("O caractere %c foi encontrado na position %ld", c, result - str);
	}
	else {
		printf("%c not founded.", c);}
	return (0);
}*/

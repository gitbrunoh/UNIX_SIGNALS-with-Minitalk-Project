/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:56:26 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/25 17:53:11 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}

/*static char	ft2(unsigned int i, char s)
{
	if (i < 6)
		s = '*';
	return (s);
}

static char	ft1(unsigned int i, char s)
{
	if (i < 3)
		s = '*';
	return (s);
}

int	main()
{
	char	str[] = "password";
	ft_putstr_fd(ft_strmapi(str, ft2), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(ft_strmapi(str, ft1), 1);
}*/

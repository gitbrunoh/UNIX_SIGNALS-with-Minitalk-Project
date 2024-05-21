/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:53:22 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/18 17:32:31 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	k;
	unsigned int	i;
	unsigned int	total_len;
	char			*ptr_join;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	ptr_join = (char *)malloc(sizeof(char) * total_len + 1);
	if (ptr_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr_join[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		ptr_join[i] = s2[k];
		k++;
		i++;
	}
	ptr_join[i] = '\0';
	return (ptr_join);
}

/*int	main(void)
{
	char	*str1 = "42born";
	char	*str2 = "2code";
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	ft_putstr_fd(str3, 1);
	return (0);
}*/

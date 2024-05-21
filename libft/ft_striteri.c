/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:55:23 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/25 17:54:29 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, (s + i));
		++i;
	}
}

/*static void	ft_test(unsigned int i, char *str)
{
	if (*str >= 48 && *str <= 57)
		*str = '*';
	else
		*str = '_';
}

int	main(void)
{
	char	str[] = "my-birthday-14/02/1986";
	ft_striteri(str, ft_test);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/

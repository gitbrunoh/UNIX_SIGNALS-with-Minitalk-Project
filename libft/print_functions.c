/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:51:40 by brunhenr          #+#    #+#             */
/*   Updated: 2023/11/03 14:53:05 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		ft_print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	ft_printdgt(long int c, int base, char specifier)
{
	char	*symbols;
	char	*symbols2;
	int		count;

	symbols = "0123456789abcdef";
	symbols2 = "0123456789ABCDEF";
	if (c < 0)
	{
		write(1, "-", 1);
		c = -c;
		return (ft_printdgt(c, base, specifier) + 1);
	}
	else if (c < base)
	{
		if (specifier == 'X')
			return (ft_print_char(symbols2[c]));
		return (ft_print_char(symbols[c]));
	}
	else
	{
		count = ft_printdgt(c / base, base, specifier);
		return (count + ft_printdgt(c % base, base, specifier));
	}
}

int	ft_print_ptr(unsigned long c)
{
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	if (c < 16)
		return (ft_print_char(symbols[c]));
	else
	{
		count = ft_print_ptr(c / 16);
		return (count + ft_print_ptr(c % 16));
	}
}

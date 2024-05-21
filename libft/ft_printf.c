/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:27:32 by brunhenr          #+#    #+#             */
/*   Updated: 2023/11/03 15:55:50 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format(*++format, ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

int	ft_print_format(char specifier, va_list ap)
{
	unsigned long	arg_ptr;
	int				count;

	count = 0;
	if (specifier == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (specifier == 'p')
	{
		count = get_ptr_arg(&arg_ptr, ap);
		if (arg_ptr == 0)
			return (count);
		return (count + ft_print_ptr(arg_ptr));
	}
	else if (specifier == 'd' || specifier == 'i')
		return (ft_printdgt((long)va_arg(ap, int), 10, specifier));
	else if (specifier == 'u')
		return (ft_printdgt((long)va_arg(ap, unsigned int), 10, specifier));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_printdgt((long)va_arg(ap, unsigned int), 16, specifier));
	else
		return (write(1, &specifier, 1));
	return (0);
}

int	get_ptr_arg(unsigned long *arg_ptr, va_list ap)
{
	int	count;

	count = 0;
	*arg_ptr = (va_arg(ap, unsigned long));
	if (*arg_ptr == 0)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count = write(1, "0x", 2);
	return (count);
}

/*int	main(void)
{
	char	*str;
	int	count;

	str = "42BornToCode";

	write(1, "\n---Char (c)---\n", 17);
	count = ft_printf("%c", 'a');
	printf("\nChars written: %d\n", count);
	count = printf("%c", 'a');
	printf("\nChars written: %d\n\n\n", count);

	write(1, "---String (s)--\n", 17);
	count = ft_printf("%s", str);
	printf("\nChars written: %d\n", count);
	count = printf("%s", str);
	printf("\nChars written: %d\n\n\n", count);

	write(1, "--Decimal (d)--\n", 17);
	count = ft_printf("%d", -1);
	printf("\nChars written: %d\n", count);
	count = printf("%d", -1);
	printf("\nChars written: %d\n\n\n", count);

	write(1, "Hexadecimal (x)\n", 17);
	count = ft_printf("%X", -1);
	printf("\nChars written: %d\n", count);
	count = printf("%X", -1);
	printf("\nChars written: %d\n\n\n", count);

	write(1, "--Integer (i)--\n", 17);
	count = ft_printf("%i", -15);
	printf("\nChars written: %d\n", count);
	count = printf("%i", -15);
	printf("\nChars written: %d\n\n\n", count);

	write(1, "_Unsigned__ (u)\n", 17);
	count = ft_printf("%u", -1);
	printf("\nChars written: %d\n", count);
	count = printf("%u", -1);
	printf("\nChars written: %d\n\n\n", count);
	
	write(1, "--Pointer (p)--\n", 17);
	count = ft_printf("'NULL': %p 'str address': %p", NULL, str);
	printf("\nChars written: %d\n", count);
	count = printf("'NULL': %p 'str address': %p", NULL, str);
	printf("\nChars written: %d\n\n\n", count);

	write(1, "--The '%' Test--\n", 17);
	count = ft_printf("An alone %%");
	printf("\nChars written: %d\n", count);
	count = printf("An alone %%");
	printf("\nChars written: %d\n", count);
	
	return (0);
}*/
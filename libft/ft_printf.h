/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:52:21 by brunhenr          #+#    #+#             */
/*   Updated: 2023/11/04 14:59:08 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	get_ptr_arg(unsigned long *arg_ptr, va_list ap);
int	ft_printf(const char *format, ...);
int	ft_print_format(char specifier, va_list ap);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_printdgt(long int c, int base, char specifier);
int	ft_print_ptr(unsigned long c);

#endif

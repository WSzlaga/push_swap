/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiktoria <wiktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:53:40 by wszlaga           #+#    #+#             */
/*   Updated: 2026/05/27 12:41:36 by wiktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_which_one(va_list args, const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (format[i] == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (format[i] == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (format[i] == 'i' || format[i] == 'd')
		count += ft_print_nbr(va_arg(args, int));
	else if (format[i] == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (format[i] == 'u')
		count += ft_print_unsigned((unsigned long)va_arg(args, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		count += ft_print_hex((unsigned int)va_arg(args, int), format[i]);
	else if (format[i] == '%')
	{
		write(1, "%%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
			count += ft_which_one(args, &format[i++ + 1]);
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end (args);
	return (count);
}

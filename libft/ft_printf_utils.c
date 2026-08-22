/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiktoria <wiktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:12:20 by wszlaga           #+#    #+#             */
/*   Updated: 2026/05/27 12:10:32 by wiktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_str("(null)"));
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	char	*tekst;
	int		len;

	tekst = ft_itoa(n);
	len = ft_print_str(tekst);
	free(tekst);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	len += ft_print_str("0x");
	len += ft_print_hex((unsigned long)ptr, 'x');
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*base;

	base = "0123456789";
	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	ft_print_char(base[n % 10]);
	len++;
	return (len);
}

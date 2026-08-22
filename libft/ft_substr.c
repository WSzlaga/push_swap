/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:56 by wszlaga           #+#    #+#             */
/*   Updated: 2025/11/06 15:38:56 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*c;
	int				i;
	unsigned int	rozmiar;

	i = 0;
	rozmiar = (unsigned int) ft_strlen(s);
	if (len > (rozmiar - start))
		len = rozmiar - start;
	if (rozmiar < start)
	{
		c = malloc(1);
		c[0] = '\0';
		return (c);
	}
	c = malloc(len + 1);
	if (!c || !s)
		return (NULL);
	while (s && len-- > 0)
	{
		c[i++] = s[start++];
	}
	c[i] = '\0';
	return (c);
}

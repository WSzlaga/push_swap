/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiktoria <wiktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:18:08 by wszlaga           #+#    #+#             */
/*   Updated: 2026/05/27 12:40:07 by wiktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	if (!s1 || !s2 || n == 0)
		return (0);
	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	i = 0;
	while (i < (n - 1) && t_s1 && t_s2)
	{
		if (t_s1[i] != t_s2[i])
			return (t_s1[i] - t_s2[i]);
		i++;
	}
	return (t_s1[i] - t_s2[i]);
}

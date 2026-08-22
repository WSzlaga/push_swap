/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiktoria <wiktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:50:18 by wszlaga           #+#    #+#             */
/*   Updated: 2026/05/27 12:40:30 by wiktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	while (n > 0)
	{
		*(temp_dst++) = *(temp_src++);
		n--;
	}
	return (dst);
}

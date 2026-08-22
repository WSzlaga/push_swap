/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiktoria <wiktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:50:21 by wszlaga           #+#    #+#             */
/*   Updated: 2026/05/27 12:41:00 by wiktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp_src;
	char	*temp_dst;

	temp_src = (char *) src;
	temp_dst = (char *) dst;
	if (temp_dst < temp_src)
		while (len--)
			*temp_dst++ = *temp_src++;
	else
	{
		while (len--)
			temp_dst[len] = temp_src[len];
	}
	return (dst);
}

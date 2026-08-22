/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:46:06 by wszlaga           #+#    #+#             */
/*   Updated: 2025/11/06 15:52:20 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 0;
		size = 0;
	}
	else if (size > 0 && nmemb > (SIZE_MAX / size))
	{
		return (NULL);
	}
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, size * nmemb);
	return (temp);
}

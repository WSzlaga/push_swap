/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:35:03 by wszlaga           #+#    #+#             */
/*   Updated: 2025/10/24 18:24:18 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;

	i = -1;
	c = malloc(ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	while (s[++i])
		c[i] = s[i];
	c[i] = 0;
	return (c);
}

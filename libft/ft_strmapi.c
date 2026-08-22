/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:06:16 by wszlaga           #+#    #+#             */
/*   Updated: 2025/11/06 15:48:47 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ss;

	ss = malloc(ft_strlen(s) + 1);
	if (!ss)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ss[i] = (*f)(i, s[i]);
		i++;
	}
	ss[i] = 0;
	return (ss);
}

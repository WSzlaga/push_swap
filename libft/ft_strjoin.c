/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiktoria <wiktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:24:22 by wszlaga           #+#    #+#             */
/*   Updated: 2026/05/27 12:42:17 by wiktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_j;
	int		i;
	int		j;
	size_t	rozmiar;

	i = 0;
	j = 0;
	rozmiar = (ft_strlen(s1) + ft_strlen(s2));
	str_j = (char *)malloc(rozmiar + 1);
	if (!str_j || (!s1 && !s2))
		return (NULL);
	while (s1[i])
		str_j[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str_j[j++] = s2[i++];
	str_j[j] = '\0';
	return (str_j);
}

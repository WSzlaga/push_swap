/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:49:48 by wszlaga           #+#    #+#             */
/*   Updated: 2026/08/29 08:54:42 by wszlaga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	how_words(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	length;

	words = 0;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		while (s[i] != c && s[i])
			i++;
		words++;
	}
	return (words);
}

static void	find_words(char const *s, char c, size_t *i, size_t *start)
{
	while (s[*i] == c)
		(*i)++;
	*start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;
	size_t	start;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = ft_calloc((how_words(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		find_words(s, c, &i, &start);
		if (start < i)
		{
			str[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

void free_split(char **split)
{
    int i;

    i = 0;
    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
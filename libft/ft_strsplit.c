/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:15:19 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/11 12:06:37 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void		ft_free_strings(char **strings, size_t a)
{
	size_t i;

	i = 0;
	while (i < a)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static size_t	ft_slen(char const *s, int i, char c)
{
	size_t x;

	x = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		x++;
	}
	return (x);
}

static char		**ft_fill_strings(char **strings, char const *s, char c, int wc)
{
	int a;
	int i;
	int slen;

	a = 0;
	i = 0;
	while (a < wc)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			slen = ft_slen(s, i, c);
			if (!(strings[a] = ft_strsub(s, i, slen)))
			{
				ft_free_strings(strings, a);
				return (NULL);
			}
			i = i + slen;
		}
		a++;
	}
	strings[a] = 0;
	return (strings);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		word_count;

	word_count = ft_word_count(s, c);
	if (!(strings = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	strings = ft_fill_strings(strings, s, c, word_count);
	return (strings);
}

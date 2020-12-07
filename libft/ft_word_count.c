/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:38:58 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/09 21:11:05 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_word_count(char const *s, char c)
{
	size_t i;
	size_t w;
	size_t w_count;

	w = 0;
	w_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			w = 0;
		else if (w == 0)
		{
			w = 1;
			w_count++;
		}
		i++;
	}
	return (w_count);
}

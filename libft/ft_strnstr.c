/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:49:35 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/14 17:34:47 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t a;
	size_t l;

	i = 0;
	if (!(l = ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		a = 0;
		while (needle[a] == haystack[i + a] && needle[a] != '\0' && i + a < len)
		{
			a++;
		}
		if (needle[a] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

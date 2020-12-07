/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 00:42:18 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/04 17:28:40 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	x;
	int		i;

	i = 0;
	x = c;
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return ((char *)s + i);
		i++;
	}
	if (x == '\0')
		return ((char *)s + i);
	else
		return (NULL);
}

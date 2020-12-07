/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 23:04:08 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/10 23:19:36 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	x;

	x = c;
	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == x)
			return (&a[i]);
		i++;
	}
	return (NULL);
}

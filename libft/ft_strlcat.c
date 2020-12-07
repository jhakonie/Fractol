/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 20:11:52 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/11 00:17:43 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t d_len;
	size_t s_len;
	size_t n;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	n = d_len + s_len;
	if (dstsize <= d_len)
		return (s_len + dstsize);
	i = 0;
	while (dst[i] != '\0' && i < (dstsize - 1))
		i++;
	while (*src && i < (dstsize - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (n);
}

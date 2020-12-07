/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 10:33:03 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/04 17:23:20 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s12;
	unsigned char	*s22;
	size_t			i;

	s12 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	if (*s12 == 0 && *s22 == 0)
		return (0);
	while (s12[i] == s22[i] && i < n)
	{
		if (i == n - 1)
			return (s12[i] - s22[i]);
		i++;
	}
	return (s12[i] - s22[i]);
}

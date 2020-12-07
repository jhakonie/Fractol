/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:48:50 by jhakonie          #+#    #+#             */
/*   Updated: 2020/06/30 18:36:26 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t x;

	i = 0;
	x = ft_strlen(s1);
	while (s2[i] != 0 && i < n)
	{
		s1[x] = s2[i];
		x++;
		i++;
	}
	s1[x] = '\0';
	return (s1);
}

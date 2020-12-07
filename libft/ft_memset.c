/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 18:47:50 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/10 23:14:11 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	x;

	x = c;
	str = ptr;
	i = 0;
	while (i < n)
	{
		str[i] = x;
		i++;
	}
	return (ptr);
}

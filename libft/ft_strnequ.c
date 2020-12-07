/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:08:50 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/07 12:53:10 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (s2[i] == s1[i] && s2[i] != '\0' && s1[i] != '\0' && i < n)
	{
		if (i + 1 == n)
			return (1);
		i++;
	}
	if (s1[i] - s2[i] == 0)
		return (1);
	return (0);
}

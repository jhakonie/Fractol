/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:39:02 by jhakonie          #+#    #+#             */
/*   Updated: 2020/07/04 17:31:26 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int len;

	len = ft_strlen(s);
	i = 0;
	if (s != 0 && f != 0)
	{
		while (s[i] != '\0' && i < len)
		{
			f(i, &s[i]);
			i++;
		}
	}
}

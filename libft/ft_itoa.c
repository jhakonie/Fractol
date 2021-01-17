/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 11:32:02 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/06 01:17:40 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static size_t	ft_int_len(int n)
{
	int c;

	c = 0;
	if (n < 0)
		c = 1;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static char		*ft_fill_numbers(char *str, int i, int n)
{
	while (n > 9)
	{
		str[i] = ((n % 10) + '0');
		n = (n / 10);
		i--;
	}
	str[i] = (n + '0');
	return (str);
}

static char		*ft_n_is_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_int_len(n);
	if (n == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		return (ft_n_is_zero(str));
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = -147483648;
			str[1] = '2';
		}
		str[0] = '-';
		n = n * (-1);
	}
	str = ft_fill_numbers(str, i, n);
	return (str);
}

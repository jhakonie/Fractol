/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:20:15 by jhakonie          #+#    #+#             */
/*   Updated: 2020/10/20 22:23:48 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;
	char	*new;

	l = ft_strlen(s) - 1;
	i = 0;
	while ((s[i] == 32 || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[l] == 32 || s[l] == '\t' || s[l] == '\n')
		l--;
	if (!(new = ft_strsub(s, i, (l + 1 - i))))
		return (NULL);
	return (new);
}

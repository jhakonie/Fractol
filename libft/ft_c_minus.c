/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:43:50 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/12 14:43:53 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_c_minus(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	return (res);
}

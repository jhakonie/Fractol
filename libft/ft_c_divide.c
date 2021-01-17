/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:43:38 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/12 14:43:41 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_c_divide(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = (a.x * b.x + a.y * b.y) / (b.x * b.x + b.y * b.y);
	res.y = (-a.x * b.y + b.x * a.y) / (b.x * b.x + b.y * b.y);
	return (res);
}

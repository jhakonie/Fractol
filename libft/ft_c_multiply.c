/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_multiply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:43:14 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/12 14:44:04 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_c_multiply(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = a.x * b.x - a.y * b.y;
	res.y = a.x * b.y + a.y * b.x;
	return (res);
}

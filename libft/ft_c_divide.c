/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_divide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:55:49 by johku             #+#    #+#             */
/*   Updated: 2020/12/20 00:06:56 by johku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_c_divide(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = (a.x * b.x + a.y * b.y) / (b.x * b.x - b.y * b.y);
	res.y = (a.x * b.y + b.x * a.y) / (b.x * b.x - b.y * b.y);
	return (res);
}

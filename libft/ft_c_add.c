/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:58:43 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/01 23:06:50 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex	ft_c_add(t_complex a, t_complex b)
{
	t_complex res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

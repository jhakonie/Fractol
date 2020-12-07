/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_sqred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:07:06 by jhakonie          #+#    #+#             */
/*   Updated: 2020/12/07 21:57:38 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex	ft_c_sqred(t_complex a)
{
	t_complex res;

	res.x = a.x * a.x - a.y * a.y;
	res.y = 2 * a.x * a.y;
	return (res);
}

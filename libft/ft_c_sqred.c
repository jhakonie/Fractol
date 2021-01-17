/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_sqred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakonie <jhakonie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:44:12 by jhakonie          #+#    #+#             */
/*   Updated: 2021/01/12 14:44:15 by jhakonie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_c_sqred(t_complex a)
{
	t_complex	res;

	res.x = a.x * a.x - a.y * a.y;
	res.y = 2 * a.x * a.y;
	return (res);
}

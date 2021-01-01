/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johku <johku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:45:24 by johku             #+#    #+#             */
/*   Updated: 2020/12/19 23:48:11 by johku            ###   ########.fr       */
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
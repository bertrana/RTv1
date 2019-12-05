/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:50 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 05:17:17 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

long double	vector_scalar(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

long double	vector_length(t_vector a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

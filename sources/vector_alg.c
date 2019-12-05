/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:42 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 03:37:42 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector	vector_minus(t_vector a, t_vector b)
{
	t_vector	ans;

	ans.x = a.x - b.x;
	ans.y = a.y - b.y;
	ans.z = a.z - b.z;
	return (ans);
}

t_vector	vector_plus(t_vector a, t_vector b)
{
	t_vector	ans;

	ans.x = a.x + b.x;
	ans.y = a.y + b.y;
	ans.z = a.z + b.z;
	return (ans);
}

t_vector	vector_multi(long double a, t_vector v)
{
	v.x *= a;
	v.y *= a;
	v.z *= a;
	return (v);
}

t_vector	vector_new(long double x, long double y, long double z)
{
	t_vector	ans;

	ans.x = x;
	ans.y = y;
	ans.z = z;
	return (ans);
}

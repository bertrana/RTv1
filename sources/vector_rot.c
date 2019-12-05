/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:45 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 03:37:45 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector	rotate_x(t_vector vec, long double angle)
{
	t_vector	ans;

	angle = angle * M_PI / 180;
	ans.x = vec.x;
	ans.y = vec.y * cos(angle) - vec.z * sin(angle);
	ans.z = vec.y * sin(angle) + vec.z * cos(angle);
	return (ans);
}

t_vector	rotate_y(t_vector vec, long double angle)
{
	t_vector	ans;

	angle = angle * M_PI / 180;
	ans.x = vec.x * cos(angle) + vec.z * sin(angle);
	ans.y = vec.y;
	ans.z = vec.x * -sin(angle) + vec.z * cos(angle);
	return (ans);
}

t_vector	rotate_z(t_vector vec, long double angle)
{
	t_vector	ans;

	angle = angle * M_PI / 180;
	ans.x = vec.x * cos(angle) - vec.y * sin(angle);
	ans.y = vec.x * sin(angle) + vec.y * cos(angle);
	ans.z = vec.z;
	return (ans);
}

t_vector	apply_rotate(t_vector d, t_vector angles)
{
	d = rotate_x(d, angles.x);
	d = rotate_y(d, angles.y);
	d = rotate_z(d, angles.z);
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:08 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 03:37:08 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector	get_cone_coeffs(t_vector o, t_vector d, t_figure f)
{
	long double		k1;
	long double		k2;
	long double		k3;
	t_vector		t;
	t_vector		s;

	t = vector_minus(d, vector_multi(vector_scalar(d, f.rotation),
				f.rotation));
	s = vector_minus(vector_minus(o, f.base),
			vector_multi(vector_scalar(vector_minus(o, f.base), f.rotation),
				f.rotation));
	k1 = pow(cos(f.radius / 2), 2) * vector_scalar(t, t)
		- pow(sin(f.radius / 2), 2) * pow(vector_scalar(d, f.rotation), 2);
	k2 = 2 * pow(cos(f.radius / 2), 2) * vector_scalar(t, s)
		- 2 * pow(sin(f.radius / 2), 2) * vector_scalar(d, f.rotation)
		* vector_scalar(vector_minus(o, f.base), f.rotation);
	k3 = pow(cos(f.radius / 2), 2) * vector_scalar(s, s)
		- pow(sin(f.radius / 2), 2)
		* pow(vector_scalar(vector_minus(o, f.base), f.rotation), 2);
	return (vector_new(k1, k2, k3));
}

t_vector	get_cylinder_coeffs(t_vector o, t_vector d, t_figure f)
{
	long double		k1;
	long double		k2;
	long double		k3;
	t_vector		t;
	t_vector		s;

	t = vector_minus(d,
			vector_multi(vector_scalar(d, f.rotation), f.rotation));
	s = vector_minus(vector_minus(o, f.base),
			vector_multi(vector_scalar(vector_minus(o, f.base), f.rotation),
		f.rotation));
	k1 = vector_scalar(t, t);
	k2 = 2 * vector_scalar(t, s);
	k3 = vector_scalar(s, s) - pow(f.radius, 2);
	return (vector_new(k1, k2, k3));
}

t_vector	get_sphere_coeffs(t_vector o, t_vector d, t_figure figure)
{
	long double		k1;
	long double		k2;
	long double		k3;
	t_vector		oc;

	oc = vector_minus(o, figure.base);
	k1 = vector_scalar(d, d);
	k2 = 2 * vector_scalar(oc, d);
	k3 = vector_scalar(oc, oc) - pow(figure.radius, 2);
	return (vector_new(k1, k2, k3));
}

t_roots		solve_quadratic(t_vector o, t_vector d, t_figure figure)
{
	t_roots			roots;
	t_vector		c;
	long double		desc;

	if (figure.type == SPHERE)
		c = get_sphere_coeffs(o, d, figure);
	if (figure.type == CYLINDER)
		c = get_cylinder_coeffs(o, d, figure);
	if (figure.type == CONE)
		c = get_cone_coeffs(o, d, figure);
	desc = c.y * c.y - 4 * c.x * c.z;
	if (desc < 0)
	{
		roots.x1 = INF;
		roots.x2 = INF;
		return (roots);
	}
	roots.x1 = (-c.y + sqrt(desc)) / (2 * c.x);
	roots.x2 = (-c.y - sqrt(desc)) / (2 * c.x);
	return (roots);
}

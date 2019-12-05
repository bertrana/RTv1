/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shine.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:21 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 05:04:44 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

long double	cone_shine(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_vector	l;
	t_vector	n;
	t_vector	u;
	t_figure	sph;
	t_roots		ro;

	sph.type = SPHERE;
	sph.radius = vector_length(vector_minus(f.base, w->p)) * tan(f.radius / 2);
	sph.base = w->p;
	ro = solve_quadratic(f.base, f.rotation, sph);
	u.y = (fabsl(ro.x1) > fabsl(ro.x2)) ? ro.x1 : ro.x2;
	n = vector_minus(vector_plus(f.base, vector_multi(u.y, f.rotation)), w->p);
	n = vector_multi(1 / vector_length(n), n);
	l = vector_multi(1 / vector_length(vector_minus(w->p, l_vector)),
vector_minus(w->p, l_vector));
	n = vector_minus(vector_multi(2 * vector_scalar(n, l), n), l);
	u.x = vector_scalar(n, vector_minus(w->p, w->camera.position));
	return (fabsl(u.x) / (vector_length(n)
	* vector_length(vector_minus(w->p, w->camera.position))));
}

long double	cylinder_shine(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_vector	l;
	t_vector	n;
	t_vector	u;
	t_figure	sph;
	t_roots		ro;

	sph.type = SPHERE;
	sph.radius = f.radius + vector_length(w->p) * 0.00005;
	sph.base = w->p;
	ro = solve_quadratic(f.base, f.rotation, sph);
	u.y = (fabsl(ro.x1) > fabsl(ro.x2)) ? ro.x1 : ro.x2;
	l = vector_minus(w->p, l_vector);
	n = vector_minus(vector_plus(f.base, vector_multi(u.y, f.rotation)), w->p);
	n = vector_multi(1 / vector_length(n), n);
	l = vector_multi(1 / vector_length(l), l);
	n = vector_minus(vector_multi(2 * vector_scalar(n, l), n), l);
	u.x = vector_scalar(n, vector_minus(w->p, w->camera.position));
	return (fabsl(u.x) / (vector_length(n)
	* vector_length(vector_minus(w->p, w->camera.position))));
}

long double	sphere_shine(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_vector		l;
	t_vector		n;
	t_vector		r;
	long double		r_dot_v;

	n = vector_minus(w->p, f.base);
	l = vector_minus(w->p, l_vector);
	n = vector_multi(1 / vector_length(n), n);
	l = vector_multi(1 / vector_length(l), l);
	r = vector_minus(vector_multi(2 * vector_scalar(n, l), n), l);
	r_dot_v = vector_scalar(r, vector_minus(w->p, w->camera.position));
	return (fabsl(r_dot_v) / (vector_length(r)
	* vector_length(vector_minus(w->p, w->camera.position))));
}

long double	plane_shine(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_vector		l;
	t_vector		n;
	t_vector		r;
	long double		r_dot_v;

	n = f.rotation;
	l = vector_multi(1 / vector_length(vector_minus(w->p, l_vector)),
vector_minus(l_vector, w->p));
	r = vector_minus(vector_multi(2 * vector_scalar(n, l), n), l);
	r_dot_v = vector_scalar(r, vector_minus(w->p, w->camera.position));
	return (fabsl(r_dot_v) / (vector_length(r)
	* vector_length(vector_minus(w->p, w->camera.position))));
}

long double	s_by_type(t_figure f, t_mlx *w, int l_id)
{
	if (f.type == SPHERE)
		return (sphere_shine(f, w, w->lights[l_id].vector));
	if (f.type == CYLINDER)
		return (cylinder_shine(f, w, w->lights[l_id].vector));
	if (f.type == CONE)
		return (cone_shine(f, w, w->lights[l_id].vector));
	if (f.type == PLANE)
		return (plane_shine(f, w, w->lights[l_id].vector));
	return (0);
}

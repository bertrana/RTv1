/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:36:22 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 03:36:22 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

long double		cone_light(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_figure		sph;
	t_roots			ro;
	t_vector		l;
	t_vector		n;
	long double		ans1;

	sph.type = SPHERE;
	sph.radius = vector_length(vector_minus(f.base, w->p)) * tan(f.radius / 2);
	sph.base = w->p;
	ro = solve_quadratic(f.base, f.rotation, sph);
	ans1 = (fabsl(ro.x1) > fabsl(ro.x2)) ? ro.x1 : ro.x2;
	n = vector_minus(vector_plus(f.base, vector_multi(ans1, f.rotation)), w->p);
	n = vector_multi(1 / vector_length(n), n);
	l = vector_multi(1 / vector_length(vector_minus(w->p, l_vector)),
			vector_minus(w->p, l_vector));
	return (vector_scalar(n, l));
}

long double		cylinder_light(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_figure		sph;
	t_roots			ro;
	t_vector		l;
	t_vector		n;
	long double		ans1;

	sph.type = SPHERE;
	sph.radius = f.radius + vector_length(w->p) * 0.00001;
	sph.base = w->p;
	ro = solve_quadratic(f.base, f.rotation, sph);
	ans1 = (fabsl(ro.x1) > fabsl(ro.x2)) ? ro.x1 : ro.x2;
	n = vector_minus(vector_plus(f.base,
				vector_multi(ans1, f.rotation)), w->p);
	n = vector_multi(1 / vector_length(n), n);
	l = vector_multi(1 / vector_length(vector_minus(w->p, l_vector)),
			vector_minus(w->p, l_vector));
	return (vector_scalar(n, l));
}

long double		sphere_light(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_vector	l;
	t_vector	n;

	n = vector_multi(1 / vector_length(vector_minus(f.base, w->p)),
			vector_minus(f.base, w->p));
	l = vector_multi(1 / vector_length(vector_minus(w->p, l_vector)),
			vector_minus(w->p, l_vector));
	return (vector_scalar(n, l));
}

long double		l_by_type(t_figure f, t_mlx *w, int l_id)
{
	if (f.type == SPHERE)
		return (fabsl(sphere_light(f, w, w->lights[l_id].vector)));
	if (f.type == CYLINDER)
		return (fabsl(cylinder_light(f, w, w->lights[l_id].vector)));
	if (f.type == CONE)
		return (fabsl(cone_light(f, w, w->lights[l_id].vector)));
	if (f.type == PLANE)
		return (fabsl(plane_light(f, w, w->lights[l_id].vector)));
	return (0);
}

/*
** t_vector util (x, y, z) (i, max, ...)
*/

/*
** else
** w->l = w->lights[(int)util.x].vector;
*/

t_lightning		calculate_lightning(t_closest_figure c, t_mlx *w)
{
	t_lightning		ans;
	t_vector		util;

	util = vector_new(-1, INF, 0);
	ans.offset = 0;
	ans.shine = 0;
	while (++util.x < w->en.lights)
	{
		if (w->lights[(int)util.x].type == AMBIENT)
			ans.offset += w->lights[(int)util.x].intensity;
		else
		{
			if (w->lights[(int)util.x].type == POINT && (util.y = 1))
				w->l = vector_minus(w->lights[(int)util.x].vector, w->p);
			if (get_closest_figure(w->p, w->l, w, util.y).flag)
				continue ;
			ans.offset += w->lights[(int)util.x].intensity
				* l_by_type(c.figure, w, util.x);
			if (c.figure.specular != -1)
				ans.shine += w->lights[(int)util.x].intensity
				* pow(s_by_type(c.figure, w, util.x), c.figure.specular);
		}
	}
	return (ans);
}

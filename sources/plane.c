/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:00 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 05:04:44 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

long double	plane_light(t_figure f, t_mlx *w, t_vector l_vector)
{
	t_vector	l;
	t_vector	n;

	n = f.rotation;
	l = vector_multi(1 / vector_length(vector_minus(w->p, l_vector)),
			vector_minus(l_vector, w->p));
	return (vector_scalar(n, l));
}

t_roots		solve_plane(t_vector o, t_vector d, t_figure plane)
{
	t_roots			roots;
	long double		konst;
	long double		t;

	konst = vector_scalar(plane.rotation, plane.base);
	t = (konst - vector_scalar(o, plane.rotation)) /
		vector_scalar(d, plane.rotation);
	roots.x1 = t;
	roots.x2 = t;
	return (roots);
}

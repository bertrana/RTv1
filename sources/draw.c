/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:31 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 05:12:25 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_roots				closest_help(t_vector o, t_vector d, t_figure f)
{
	if (f.type == PLANE)
		return (solve_plane(o, d, f));
	return (solve_quadratic(o, d, f));
}

t_closest_figure	get_closest_figure(t_vector o, t_vector d,
										t_mlx *w, long double max)
{
	t_closest_figure	ans;
	t_roots				roots;
	int					i;

	ans.closest = max;
	ans.flag = 0;
	i = -1;
	while (++i < w->en.figures)
	{
		roots = closest_help(o, d, w->figures[i]);
		if (roots.x1 > 0.001 && roots.x1 < max && roots.x1 < ans.closest)
		{
			ans.closest = roots.x1;
			ans.figure = w->figures[i];
			ans.flag = 1;
		}
		if (roots.x2 > 0.001 && roots.x2 < max && roots.x2 < ans.closest)
		{
			ans.closest = roots.x2;
			ans.figure = w->figures[i];
			ans.flag = 1;
		}
	}
	return (ans);
}

int					calculate_color(t_lightning l, t_figure f)
{
	int r;
	int g;
	int b;

	r = (int)((f.color & 0xff0000) * l.offset) & 0xff0000;
	g = (int)((f.color & 0x00ff00) * l.offset) & 0x00ff00;
	b = (int)((f.color & 0x0000ff) * l.offset) & 0x0000ff;
	r = r + ((int)((f.color & 0xff0000) * l.shine) & 0xff0000);
	if (r > 0xff0000)
		r = 0xff0000;
	g = g + ((int)((f.color & 0x00ff00) * l.shine) & 0x00ff00);
	if (g > 0x00ff00)
		g = 0x00ff00;
	b = b + ((int)((f.color & 0x0000ff) * l.shine) & 0x0000ff);
	if (b > 0x0000ff)
		b = 0x0000ff;
	return (r | g | b);
}

int					trace_ray(t_vector d, t_mlx *w)
{
	t_closest_figure	c;
	t_lightning			l;

	c = get_closest_figure(w->camera.position, d, w, INF);
	if (!c.flag)
		return (0);
	w->p = vector_plus(w->camera.position, vector_multi(c.closest, d));
	l = calculate_lightning(c, w);
	return (calculate_color(l, c.figure));
}

void				draw(t_mlx *w)
{
	long double		x;
	long double		y;
	int				color;
	t_vector		d;

	y = -SIZE_Y / 2;
	while (y < SIZE_Y / 2)
	{
		x = -SIZE_X / 2;
		while (x < SIZE_X / 2)
		{
			d = vector_new(-x * 2 / SIZE_X, -y * 2 / SIZE_Y, 1);
			d = apply_rotate(d, w->camera.rotation);
			color = trace_ray(d, w);
			mlx_pixel_put(w->mlx_ptr, w->win_ptr,
						x + SIZE_X / 2, y + SIZE_Y / 2, color);
			x++;
		}
		y++;
	}
}

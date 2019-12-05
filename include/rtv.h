/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:57 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 05:26:00 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# define SIZE_X 900
# define SIZE_Y 900
# define INF 9999

typedef enum		e_const_lights
{
	AMBIENT,
	POINT
}					t_const_lights;

typedef enum		e_const_figures
{
	SPHERE,
	CYLINDER,
	PLANE,
	CONE
}					t_const_figures;

typedef struct		s_vector
{
	long double			x;
	long double			y;
	long double			z;
}					t_vector;

typedef struct		s_cam
{
	t_vector		position;
	t_vector		rotation;
}					t_cam;

typedef struct		s_roots
{
	long double				x1;
	long double				x2;
}					t_roots;

typedef struct		s_light
{
	short			type;
	long double		intensity;
	t_vector		vector;
}					t_light;

typedef struct		s_figure
{
	short			type;
	int				color;
	int				specular;
	long double		radius;
	t_vector		angle;
	t_vector		base;
	t_vector		rotation;
}					t_figure;

typedef struct		s_lightning
{
	long double		offset;
	long double		shine;
}					t_lightning;

typedef struct		s_closest_figure
{
	t_figure		figure;
	long double		closest;
	short			flag;
}					t_closest_figure;

typedef struct		s_entities
{
	short			figures;
	short			lights;
	short			cam;
}					t_entities;

typedef struct		s_window
{
	t_entities		en;
	t_cam			camera;
	t_figure		*figures;
	t_light			*lights;
	t_vector		p;
	t_vector		n;
	t_vector		l;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	int				*d;
	int				bpp;
	int				size_l;
	int				e;
}					t_mlx;

void				draw(t_mlx *w);
t_lightning			calculate_lightning(t_closest_figure c, t_mlx *w);
t_closest_figure	get_closest_figure(t_vector o,
										t_vector d, t_mlx *w, long double max);
int					trace_ray(t_vector d, t_mlx *w);
long double			plane_light(t_figure f, t_mlx *w, t_vector l_vector);
t_roots				solve_quadratic(t_vector o, t_vector d, t_figure figure);
t_entities			count_entities(char *filename);
int					parse_entities(char *filename, t_mlx *w);
int					err_exit(char *str);
t_vector			vector_parse(char *str);
void				free_arr(char **arr);
int					parse_color_from_hex(char *str);
int					check_by_type(char *line, int i);
t_vector			apply_rotate(t_vector d, t_vector angles);
t_vector			vector_new(long double x, long double y, long double z);
t_vector			vector_minus(t_vector a, t_vector b);
t_vector			vector_plus(t_vector a, t_vector b);
t_vector			vector_multi(long double a, t_vector v);
long double			vector_scalar(t_vector a, t_vector b);
long double			vector_length(t_vector a);
long double			plane_light(t_figure f, t_mlx *w, t_vector l_vector);
t_roots				solve_plane(t_vector o, t_vector d, t_figure plane);
long double			s_by_type(t_figure f, t_mlx *w, int l_id);

#endif

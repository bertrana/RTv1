/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:37:16 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:20:59 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_entities	count_entities(char *filename)
{
	t_entities	ans;
	int			fd;
	char		*line;

	ans.cam = 0;
	ans.figures = 0;
	ans.lights = 0;
	if (!(fd = open(filename, O_RDONLY, 0)))
		return (ans);
	while (get_next_line(fd, &line) > 0)
	{
		if (check_by_type(line, 1))
			ans.figures++;
		if (check_by_type(line, 2))
			ans.lights++;
		if (ft_strnstr(line, "CAM:", 4))
			ans.cam++;
		free(line);
	}
	free(line);
	close(fd);
	return (ans);
}

/*
** CYLINDER:        - name
** -30,0,0          - base vector
** 0,0,-45          - rotation
** 00ff00           - color
** 15               - radius / rogatka
** 1000             - specular
*/

void		check_figures(char *line, int pos, t_figure *fig)
{
	t_figure	f;
	char		**a;

	a = ft_strsplit(line, ' ');
	if (!a[0] || !a[1] || !a[2] || !a[3] || !a[4] || !a[5])
		err_exit("no 6 parts of figure");
	f.base = vector_parse(a[1]);
	f.angle = vector_parse(a[2]);
	f.color = parse_color_from_hex(a[3]);
	f.radius = ft_atoi(a[4]);
	f.specular = ft_atoi(a[5]);
	free_arr(a);
	if (ft_strnstr(line, "PLANE:", 6))
		f.type = PLANE;
	if (ft_strnstr(line, "CONE:", 5) && (f.radius *= M_PI / 180))
		f.type = CONE;
	if (ft_strnstr(line, "CYLINDER:", 9))
		f.type = CYLINDER;
	if (ft_strnstr(line, "SPHERE:", 7))
		f.type = SPHERE;
	f.rotation = apply_rotate(vector_new(0, 1, 0), f.angle);
	fig[pos] = f;
}

/*
** POINT:           - name
** 0 0 0            - base vector
** 100              - intencity
*/

void		check_lights(char *line, int pos, t_light *lig)
{
	t_light		light;
	char		**arr;
	long double	l;

	ft_bzero((void *)&light, sizeof(t_light));
	arr = ft_strsplit(line, ' ');
	if (!arr[0] || !arr[1] || !arr[2])
		err_exit("no 3 parts of light");
	light.vector = vector_parse(arr[1]);
	l = ft_atoi(arr[2]);
	light.intensity = l / 1000;
	free_arr(arr);
	if (ft_strnstr(line, "POINT:", 6) != NULL)
		light.type = POINT;
	if (ft_strnstr(line, "AMBIENT:", 8) != NULL)
		light.type = AMBIENT;
	lig[pos] = light;
}

/*
** CAM:             - name
** 0 0 0            - base vector
** 0,0,-45          - rotation
*/

t_cam		check_cam(char *line)
{
	t_cam	cam;
	char	**arr;

	ft_bzero((void *)&cam, sizeof(t_light));
	arr = ft_strsplit(line, ' ');
	if (!arr[0] || !arr[1] || !arr[2])
		err_exit("no 3 parts of cam");
	cam.position = vector_parse(arr[1]);
	cam.rotation = vector_parse(arr[2]);
	free_arr(arr);
	return (cam);
}

/*
** t_vector (x, y, z)
** x - count figures, y - count lights
*/

int			parse_entities(char *filename, t_mlx *w)
{
	int			fd;
	char		*line;
	int			s;
	t_vector	count;

	if (!(fd = open(filename, O_RDONLY, 0)))
		return (0);
	count = vector_new(0, 0, 0);
	while ((s = get_next_line(fd, &line)) > 0)
	{
		if (check_by_type(line, 1))
			check_figures(line, (int)count.x++, w->figures);
		if (check_by_type(line, 2))
			check_lights(line, (int)count.y++, w->lights);
		if (ft_strnstr(line, "CAM:", 4))
			w->camera = check_cam(line);
		free(line);
	}
	if (s == -1)
		return (0);
	free(line);
	return (1);
}

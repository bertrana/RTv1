/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:36:52 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 05:26:00 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			exit_button(t_mlx *w)
{
	free(w->figures);
	free(w->lights);
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	mlx_destroy_window(w->mlx_ptr, w->win_ptr);
	free(w);
	exit(0);
}

int			key_push(int key, t_mlx *w)
{
	if (key != 53)
		return (0);
	free(w->figures);
	free(w->lights);
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	mlx_destroy_window(w->mlx_ptr, w->win_ptr);
	free(w);
	exit(0);
}

t_mlx		*ft_init(t_mlx *w, char *argv)
{
	(!(w = (t_mlx *)malloc(sizeof(t_mlx)))) && (err_exit("malloc error"));
	w->en = count_entities(argv);
	if (w->en.cam != 1 || !w->en.lights || !w->en.figures)
		err_exit("error: bad file");
	w->figures = (t_figure *)malloc(sizeof(t_figure) * w->en.figures);
	w->lights = (t_light *)malloc(sizeof(t_light) * w->en.lights);
	if (!parse_entities(argv, w))
		err_exit("parse error");
	(!(w->mlx_ptr = mlx_init())) && (err_exit("mlx error"));
	w->win_ptr = mlx_new_window(w->mlx_ptr, SIZE_X, SIZE_Y, "RTv1");
	w->img = mlx_new_image(w->mlx_ptr, SIZE_Y, SIZE_Y);
	w->d = (int *)mlx_get_data_addr(w->img, &(w->bpp), &(w->size_l), &(w->e));
	return (w);
}

int			main(int argc, char *argv[])
{
	t_mlx *w;

	(argc != 2) && (err_exit("usage: ./RTv1 scene_name"));
	w = ft_init(NULL, argv[1]);
	draw(w);
	mlx_key_hook(w->win_ptr, key_push, w);
	mlx_hook(w->win_ptr, 17, 0, exit_button, w);
	mlx_loop(w->mlx_ptr);
	return (0);
}

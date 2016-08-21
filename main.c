/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:35:40 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/21 20:31:11 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_view(t_data *data)
{
	data->cam_p = create_vect(0, 0, -10);
	data->look = create_vect(0, 0, 10);
	data->a_x = create_vect(1, 0, 0);
	data->vec_up = create_vect(0, 1, 0);
	data->view_d = 2;
	data->view_h = 1.5;
	data->view_w = 2;
	data->init_dir = normalize(subtract(data->look, data->cam_p));
	data->x_ind = data->view_w / (float)data->s_x;
	data->y_ind = data->view_h / (float)data->s_y;
}

t_ray	*hit_obj(t_data *data, t_vect fr, t_vect dir, t_ray *ray)
{
	t_info	*inf;

	inf = (t_info *)malloc(sizeof(t_info));
	inf->obj = data->obj;
	inf->fr = fr;
	inf->dir = dir;
	ray->dist = -1;
	ray->lst_obj = data->obj;
	inf->a = SQ(dir.x) + SQ(dir.y) + SQ(dir.z);
	while (inf->obj)
	{
		if ((inf->obj)->type == 1)
			ray = hit_cercle(ray, inf);
		if ((inf->obj)->type == 2)
			ray = hit_plan(ray, inf);
		if ((inf->obj)->type == 3)
			ray = hit_cylinder(ray, inf);
		inf->obj = (inf->obj)->next;
	}
	free(inf);
	return (ray);
}

void	*raytracing(void *arg)
{
	t_data	*data;
	t_ray	*ray;
	t_vect	point;
	t_vect	vec_dir;
	int		y_max;
	int		x;
	int		y;

	data = (t_data *)arg;
	data->init = 1.0 / (float)NUM_THREAD * (float)data->id;
	y = (float)data->init * (float)data->s_y;
	y_max = y + data->s_y / NUM_THREAD;
	pthread_cond_signal(&data->cond_img);
	ray = (t_ray *)malloc(sizeof(t_ray));
	while (y < y_max)
	{
		x = 0;
		while (x < data->s_x)
		{
			point = subtract(add(data->up_left, multiple_value(data->vec_right,
			data->x_ind * x)), multiple_value(data->vec_up, data->y_ind * y));
			vec_dir = normalize(subtract(point, data->cam_p));
			ray = hit_obj(data, data->cam_p, vec_dir, ray);
			if (ray->dist != -1)
				ft_setpixel(data, x, y, ft_light(ray));
			x++;
		}
		y++;
	}
	free(ray);
	pthread_exit(NULL);
}

int		build_img(t_data data)
{
	pthread_t	thread[NUM_THREAD];

	data.vec_right = multiple(data.vec_up, data.init_dir);
	data.vec_up = multiple(data.init_dir, data.vec_right);
	data.up_left = add(data.cam_p, add(multiple_value(data.init_dir,
	data.view_d), subtract(multiple_value(data.vec_up, (data.view_h / 2.0)),
	multiple_value(data.vec_right, (data.view_w / 2.0)))));
	data.img = mlx_new_image(data.mlx, data.s_x, data.s_y);
	data.disp = mlx_get_data_addr(data.img, &(data.bpp),
	&(data.sizeline), &(data.endian));
	pthread_mutex_init(&(data.mutex_img), NULL);
	pthread_cond_init(&(data.cond_img), NULL);
	data.id = 0;
	while (data.id < NUM_THREAD)
	{
		pthread_create(&thread[data.id], NULL, raytracing, &data);
		pthread_cond_wait(&data.cond_img, &data.mutex_img);
		data.id++;
	}
	data.id = 0;
	while (data.id < NUM_THREAD)
	{
		pthread_join(thread[data.id], NULL);
		data.id++;
	}
	pthread_mutex_destroy(&data.mutex_img);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_destroy_image(data.mlx, data.img);
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
		return (0);
	data.obj = ft_objects(av[1]);
	if (!data.obj)
		return (0);
	data.s_x = 720;
	data.s_y = 480;
	init_view(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.s_x, data.s_y, "RayTracer");
	build_img(data);
	mlx_key_hook(data.win, key_handle, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
}

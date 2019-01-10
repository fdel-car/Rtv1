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
		if ((inf->obj)->type == 4)
			ray = hit_cone(ray, inf);
		inf->obj = (inf->obj)->next;
	}
	free(inf);
	return (ray);
}

void	*raytracing(void *arg)
{
	t_data	*dt;
	t_ray	*ray;
	t_rt	*rt;

	dt = (t_data *)arg;
	rt = (t_rt *)malloc(sizeof(t_rt));
	if (!rt)
		pthread_exit(NULL);
	dt->init = 1.0 / (float)NUM_THREAD * (float)dt->id;
	rt->y = (float)dt->init * (float)dt->s_y;
	rt->y_max = rt->y + dt->s_y / NUM_THREAD;
	pthread_cond_signal(&dt->cond_img);
	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		pthread_exit(NULL);
	loop(dt, rt, ray);
	free(rt);
	free(ray);
	pthread_exit(NULL);
}

int		build_img(t_data data)
{
	pthread_t	thread[NUM_THREAD];

	init_data(&data);
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
	int			fd;

	if (ac != 2)
		return (0);
	fd = 0;
	data.obj = ft_objects(av[1], fd);
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

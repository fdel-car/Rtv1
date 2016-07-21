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

t_vect	create_vect(double x, double y, double z)
{
	t_vect vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

void	ft_init_cam(t_rayt *rt)
{
	rt->c_pos = create_vect(0, 0, -5);
	rt->look_at = create_vect(0, 0, 10);
	rt->vec_up = create_vect(0, 1, 0);
	rt->view_d = 2;
	rt->view_h = 1.5;
	rt->view_w = 2;
	rt->vec_dir = normalize(substract(rt->look_at, rt->c_pos));
	rt->vec_right = multiple(rt->vec_up, rt->vec_dir);
	rt->vec_up = multiple(rt->vec_dir, rt->vec_right);
	rt->up_left = add(rt->c_pos, add(multiple_value(rt->vec_dir, rt->view_d),
	substract(multiple_value(rt->vec_up, (rt->view_h / 2.0)),
	multiple_value(rt->vec_right, (rt->view_w / 2.0)))));
}

int		ft_rt(t_rayt *rt, t_graph *gr, t_obj *obj)
{
	gr->img = mlx_new_image(gr->mlx, gr->s_x, gr->s_y);
	gr->disp = mlx_get_data_addr(gr->img, &(gr->bpp), &(gr->sizeline),
			&(gr->endian));
	raytracing(rt, gr, obj);
	mlx_put_image_to_window(gr->mlx, gr->win, gr->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_obj	*obj;
	t_rayt	*rt;
	t_graph	*gr;

	if (ac != 2)
		return (0);
	rt = (t_rayt *)malloc(sizeof(t_rayt));
	gr = (t_graph *)malloc(sizeof(t_graph));
	gr->s_x = 720;
	gr->s_y = 480;
	obj = ft_objects(av[1]);
	if (!obj)
		return (0);
	ft_init_cam(rt);
	gr->mlx = mlx_init();
	gr->win = mlx_new_window(gr->mlx, gr->s_x, gr->s_y, "RayTracer");
	ft_rt(rt, gr, obj);
	mlx_loop(gr->mlx);
}

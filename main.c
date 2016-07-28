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
	rt->c_pos = create_vect(0, 0, -6);
	rt->look_at = create_vect(0, 0, 10);
	rt->vec_up = create_vect(0, 1, 0);
	rt->view_d = 2;
	rt->view_h = 1.5;
	rt->view_w = 2;
	rt->vec_dir = normalize(subtract(rt->look_at, rt->c_pos));
	rt->vec_right = multiple(rt->vec_up, rt->vec_dir);
	rt->vec_up = multiple(rt->vec_dir, rt->vec_right);
}

int		ft_rt(t_glob *gl)
{
	(gl->rt)->vec_dir = normalize(subtract((gl->rt)->look_at, (gl->rt)->c_pos));
	(gl->rt)->up_left = add((gl->rt)->c_pos, add(multiple_value(
	(gl->rt)->vec_dir, (gl->rt)->view_d), subtract(multiple_value(
	(gl->rt)->vec_up, ((gl->rt)->view_h / 2.0)), multiple_value(
	(gl->rt)->vec_right, ((gl->rt)->view_w / 2.0)))));
	(gl->gr)->img = mlx_new_image((gl->gr)->mlx, (gl->gr)->s_x, (gl->gr)->s_y);
	(gl->gr)->disp = mlx_get_data_addr((gl->gr)->img, &((gl->gr)->bpp),
	&((gl->gr)->sizeline), &((gl->gr)->endian));
	raytracing(gl->rt, gl->gr, gl->obj);
	mlx_put_image_to_window((gl->gr)->mlx, (gl->gr)->win, (gl->gr)->img, 0, 0);
	mlx_destroy_image((gl->gr)->mlx, (gl->gr)->img);
	return (0);
}

int		main(int ac, char **av)
{
	t_glob *gl;

	if (ac != 2)
		return (0);
	gl = (t_glob *)malloc(sizeof(t_glob));
	(void)av;
	gl->gr = (t_graph *)malloc(sizeof(t_graph));
	gl->rt = (t_rayt *)malloc(sizeof(t_rayt));
	(gl->gr)->s_x = 720;
	(gl->gr)->s_y = 480;
	gl->obj = ft_objects(av[1]);
	if (!(gl->obj))
		return (0);
	ft_init_cam(gl->rt);
	(gl->gr)->mlx = mlx_init();
	(gl->gr)->win = mlx_new_window((gl->gr)->mlx, (gl->gr)->s_x, (gl->gr)->s_y,
	"RayTracer");
	ft_rt(gl);
	mlx_key_hook((gl->gr)->win, ft_key, gl);
	mlx_hook((gl->gr)->win, 17, 0, ft_close, NULL);
	mlx_loop((gl->gr)->mlx);
}

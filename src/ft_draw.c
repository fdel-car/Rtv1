/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:26:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/06/02 18:25:37 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ray_light(t_ray *ray, t_obj *obj)
{
	int sh;

	ray->light = normalize(subtract(obj->pos, ray->hit_point));
	if ((ray->obj)->type == 1)
		ray->norm = normalize(subtract(ray->hit_point, (ray->obj)->pos));
	if ((ray->obj)->type == 2)
		ray->norm = (ray->obj)->norm;
	if ((ray->obj)->type == 3)
		ray->norm = norm_cylinder(ray);
	if ((ray->obj)->type == 4)
		ray->norm = norm_cone(ray);
	ray->dist_p = dist_p(ray->hit_point, obj->pos);
	ray->cosinus = dotp_n(ray->light, ray->norm);
	if (ray->cosinus > 0)
		ray->clr = add_color(ray->clr,
		multiple_color(multiple_color(obj->color, 0.25), ray->cosinus));
	sh = find_shadow(ray->lst_obj, multiple_value(ray->light, -1),
	obj->pos, ray->dist_p);
	ray->sh += sh;
	ray->refl = subtract(multiple_value(multiple_value(ray->norm,
	dotp_n(ray->norm, ray->light)), 2.0), ray->light);
	if (dotp_n(ray->light, ray->refl) > 0 && ray->sh < ray->lght &&
	(ray->obj)->type != 2 && sh == 0)
		ray->clr = add_color(ray->clr, multiple_color(obj->color,
		powf(dotp_n(ray->light, ray->refl), 42.0)));
}

int		loop_shadow(t_info *inf, t_ray *sh_ray, t_obj *obj, float dist)
{
	while (obj)
	{
		inf->obj = obj;
		if (obj->type == 1)
			sh_ray = hit_cercle(sh_ray, inf);
		if (obj->type == 2)
			sh_ray = hit_plan(sh_ray, inf);
		if (obj->type == 3)
			sh_ray = hit_cylinder(sh_ray, inf);
		if (obj->type == 4)
			sh_ray = hit_cone(sh_ray, inf);
		obj = obj->next;
	}
	free(inf);
	if (sh_ray->dist < dist - EPSILON && sh_ray->dist != -1)
	{
		free(sh_ray);
		return (1);
	}
	free(sh_ray);
	return (0);
}

void	init_data(t_data *data)
{
	data->vec_right = multiple(data->vec_up, data->init_dir);
	data->vec_up = multiple(data->init_dir, data->vec_right);
	data->up_left = add(data->cam_p, add(multiple_value(data->init_dir,
	data->view_d), subtract(multiple_value(data->vec_up, (data->view_h / 2.0)),
	multiple_value(data->vec_right, (data->view_w / 2.0)))));
	data->img = mlx_new_image(data->mlx, data->s_x, data->s_y);
	data->disp = mlx_get_data_addr(data->img, &(data->bpp),
	&(data->sizeline), &(data->endian));
	pthread_mutex_init(&(data->mutex_img), NULL);
	pthread_cond_init(&(data->cond_img), NULL);
	data->id = 0;
}

void	loop(t_data *dt, t_rt *rt, t_ray *ray)
{
	while (rt->y < rt->y_max)
	{
		rt->x = 0;
		while (rt->x < dt->s_x)
		{
			rt->point = subtract(add(dt->up_left, multiple_value(dt->vec_right,
			dt->x_ind * rt->x)), multiple_value(dt->vec_up, dt->y_ind * rt->y));
			rt->vec_dir = normalize(subtract(rt->point, dt->cam_p));
			ray = hit_obj(dt, dt->cam_p, rt->vec_dir, ray);
			if (ray->dist != -1)
				ft_setpixel(dt, rt->x, rt->y, ft_light(ray));
			rt->x++;
		}
		rt->y++;
	}
}

void	ft_setpixel(t_data *data, int x, int y, t_color color)
{
	int				i;

	if (x > data->s_x || y > data->s_y || x < 0 || y < 0)
		return ;
	i = y * data->sizeline + x * data->bpp / 8;
	data->disp[i + 2] = color.r;
	data->disp[i + 1] = color.g;
	data->disp[i] = color.b;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 17:22:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/08/21 14:40:35 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		find_shadow(t_obj *obj, t_vect dir, t_vect fr, float dist)
{
	t_ray	*sh_ray;
	t_info	*inf;

	sh_ray = (t_ray *)malloc(sizeof(t_ray));
	if (!sh_ray)
		return (0);
	inf = (t_info *)malloc(sizeof(t_info));
	if (!inf)
		return (0);
	sh_ray->dist = -1;
	inf->fr = fr;
	inf->dir = dir;
	inf->a = SQ(dir.x) + SQ(dir.y) + SQ(dir.z);
	return (loop_shadow(inf, sh_ray, obj, dist));
}

t_color	handle_shadow(t_color color, int sh, int lig, t_ray *ray)
{
	t_color temp;

	temp = multiple_color((ray->obj)->color, 0.25);
	temp = subtract_color(color, temp);
	temp = multiple_color(temp, (float)sh / (float)lig);
	temp = multiple_color(temp, 0.75);
	color = subtract_color(color, temp);
	return (color);
}

t_vect	norm_cylinder(t_ray *ray)
{
	float	t;
	t_vect	norm;
	t_vect	dir;
	t_vect	pos;

	dir = (ray->obj)->dir;
	pos = (ray->obj)->pos;
	t = (-dir.x * pos.x - dir.y * pos.y - dir.z * pos.z + ray->hit_point.x *
	dir.x + ray->hit_point.y * dir.y + ray->hit_point.z * dir.z) / (SQ(dir.x) +
	SQ(dir.y) + SQ(dir.z));
	norm = create_vect(ray->hit_point.x - (pos.x + dir.x * t), ray->hit_point.y
	- (pos.y + dir.y * t), ray->hit_point.z - (pos.z + dir.z * t));
	return (normalize(norm));
}

t_vect	norm_cone(t_ray *ray)
{
	float	t;
	float	beta;
	t_vect	dir;

	dir = (ray->obj)->dir;
	beta = dotp_n(normalize(subtract(ray->hit_point, (ray->obj)->pos)), dir);
	if ((acos(beta) * 180.0 / M_PI) > 90.0)
	{
		dir = multiple_value(dir, -1);
		beta = dotp_n(normalize(subtract(ray->hit_point, (ray->obj)->pos)),
		dir);
	}
	t = (dist_p((ray->obj)->pos, ray->hit_point) * sin(beta)) / sin(1.5708 +
	beta);
	dir = multiple_value(dir, t);
	dir = add((ray->obj)->pos, dir);
	return (normalize(subtract(ray->hit_point, dir)));
}

t_color	ft_light(t_ray *ray)
{
	t_obj	*obj;

	ray->sh = 0;
	ray->lght = 0;
	obj = ray->lst_obj;
	ray->clr = multiple_color((ray->obj)->color, 0.25);
	while (obj)
	{
		if (obj->type == 0)
			ray->lght++;
		obj = obj->next;
	}
	obj = ray->lst_obj;
	while (obj)
	{
		if (obj->type == 0)
			ray_light(ray, obj);
		obj = obj->next;
	}
	if (ray->sh)
		ray->clr = handle_shadow(ray->clr, ray->sh, ray->lght, ray);
	return (multiple_color(ray->clr, 1 / SQ(ray->dist_p / 800.0 + 1)));
}

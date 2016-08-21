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

int		find_shadow(t_obj *obj, t_vect dir, t_vect fr, double dist)
{
	t_ray	*sh_ray;
	t_info	*inf;

	sh_ray = (t_ray *)malloc(sizeof(t_ray));
	inf = (t_info *)malloc(sizeof(t_info));
	sh_ray->dist = -1;
	inf->fr = fr;
	inf->dir = dir;
	inf->a = SQ(dir.x) + SQ(dir.y) + SQ(dir.z);
	while (obj)
	{
		inf->obj = obj;
		if (obj->type == 1)
			sh_ray = hit_cercle(sh_ray, inf);
		if (obj->type == 2)
			sh_ray = hit_plan(sh_ray, inf);
		if (obj->type == 3)
			sh_ray = hit_cylinder(sh_ray, inf);
		obj = obj->next;
	}
	free(inf);
	if (sh_ray->dist < dist - EPSILON)
	{
		free(sh_ray);
		return (1);
	}
	free(sh_ray);
	return (0);
}

t_color	handle_shadow(t_color color, int sh, int lig, t_ray *ray)
{
	t_color temp;

	temp = multiple_color((ray->obj)->color, 0.25);
	temp = subtract_color(color, temp);
	temp = multiple_color(temp, (double)sh / (double)lig);
	temp = multiple_color(temp, 0.75);
	color = subtract_color(color, temp);
	return (color);
}

t_vect	norm_cylinder(t_ray *ray)
{
	double t;
	t_vect norm;
	t_vect dir;
	t_vect pos;

	dir = (ray->obj)->dir;
	pos = (ray->obj)->pos;
	t = (-dir.x * pos.x - dir.y * pos.y - dir.z * pos.z + ray->hit_point.x *
	dir.x + ray->hit_point.y * dir.y + ray->hit_point.z * dir.z) / (SQ(dir.x) +
	SQ(dir.y) + SQ(dir.z));
	norm = create_vect(ray->hit_point.x - (pos.x + dir.x * t), ray->hit_point.y
	- (pos.y + dir.y * t), ray->hit_point.z - (pos.z + dir.z * t));
	return (normalize(norm));
}

t_color	ft_light(t_ray *ray)
{
	t_color	color;
	t_vect	light;
	t_vect	norm;
	t_obj	*obj;
	float	cosinus;
	float	dist;
	int		shadow;
	int		lights;

	shadow = 0;
	lights = 0;
	obj = ray->lst_obj;
	color = multiple_color((ray->obj)->color, 0.25);
	while (obj)
	{
		if (obj->type == 0)
		{
			light = normalize(subtract(obj->pos, ray->hit_point));
			if ((ray->obj)->type == 1)
				norm = normalize(subtract(ray->hit_point, (ray->obj)->pos));
			if ((ray->obj)->type == 2)
				norm = (ray->obj)->norm;
			if ((ray->obj)->type == 3)
				norm = norm_cylinder(ray);
			dist = sqrt(SQ(ray->hit_point.x - obj->pos.x) + SQ(ray->hit_point.y
			- obj->pos.y) + SQ(ray->hit_point.z - obj->pos.z));
			cosinus = dotp_n(light, norm);
			if (cosinus > 0)
				color = add_color(color,
				multiple_color(multiple_color(obj->color, 0.25), cosinus));
			shadow += find_shadow(ray->lst_obj, multiple_value(light, -1),
			obj->pos, dist);
			lights++;
		}
		obj = obj->next;
	}
	if (shadow)
		color = handle_shadow(color, shadow, lights, ray);
	return (multiple_color(color, 1 / SQ(dist / 400.0 + 1)));
}

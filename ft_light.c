/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 14:47:27 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/21 20:30:12 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_shadow(t_obj *obj, t_rayt *rt, t_vect from, double dist)
{
	t_node	*check;

	check = (t_node *)malloc(sizeof(t_node));
	check->dist = -1;
	rt->a = pow(rt->vec_dir.x, 2) + pow(rt->vec_dir.y, 2) +
		pow(rt->vec_dir.z, 2);
	while (obj)
	{
		if (obj->type == 1)
			check = hit_cercle(rt, obj, check, from);
		if (obj->type == 2)
			check = hit_plan(rt, obj, check, from);
		// if (obj->type == 3)
		// 	check = hit_cylinder(rt, obj, check, from);
		obj = obj->next;
	}
	if (check->dist < dist - EPSILON)
	{
		free(check);
		return (1);
	}
	free(check);
	return (0);
}

t_color	ft_light(t_node *node, t_rayt *rt, t_obj *obj)
{
	t_color color_final;
	t_color color;
	t_vect	norm;
	double	dist;
	int		shadow;
	int		lights;

	shadow = 0;
	lights = 0;
	color_final = create_color(0, 0, 0);
	while (obj)
	{
		if (obj->type == 0)
		{
			color = multiple_color((node->obj)->color, 0.25);
			rt->light = normalize(subtract(obj->pos, node->hit_point));
			rt->vec_dir = multiple_value(rt->light, -1);
			dist = sqrt(pow(node->hit_point.x - obj->pos.x, 2) +
			pow(node->hit_point.y - obj->pos.y, 2) +
			pow(node->hit_point.z - obj->pos.z, 2));
			if ((node->obj)->type == 1)
				norm = normalize(subtract(node->hit_point, (node->obj)->pos));
			if ((node->obj)->type == 2)
				norm = (node->obj)->norm;
			// if ((node->obj)->type == 3)
			// 	norm = create_vect(node->hit_point.x, 0, node->hit_point.z);
			rt->cosinus = rt->light.x * norm.x + rt->light.y * norm.y +
			rt->light.z * norm.z;
			shadow += ft_shadow(obj, rt, obj->pos, dist);
			if (rt->cosinus >= 0)
			{
				color = add_color(color, multiple_color(obj->color,
				rt->cosinus * 0.5));
			}
			color_final = add_color(color_final, color);
			lights++;
		}
		obj = obj->next;
	}
	if (shadow)
	{
		color = multiple_color((node->obj)->color, 0.25);
		color = subtract_color(color_final, color);
		color = multiple_color(color, (double)shadow / (double)lights);
		if (shadow < lights)
			color = multiple_color(color, 0.5);
		color_final = subtract_color(color_final, color);
	}
	return (color_final);
}

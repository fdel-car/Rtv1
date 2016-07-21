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

t_color		ft_light(t_node *node, t_rayt *rt, t_obj *obj)
{
	t_color color_final;
	t_color color;
	t_vect	light;
	t_vect	norm;
	double	cosinus;

	color_final = create_color(0, 0, 0);
	while (obj)
	{
		if (obj->type == 0)
		{
			color = multiple_color((node->obj)->color, 0.25);
			light = normalize(substract(obj->pos, node->hit_point));
			norm = normalize(substract(node->hit_point, (node->obj)->pos));
			cosinus = light.x * norm.x + light.y * norm.y + light.z * norm.z;
			if (cosinus >= 0)
				color = add_color(color, multiple_color(obj->color, cosinus * 0.5));
			color_final = add_color(color_final, color);
		}
		obj = obj->next;
	}
	return color_final;
	(void)rt;
}

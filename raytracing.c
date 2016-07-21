/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:58:59 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/21 20:31:52 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	update_node(t_obj *obj, t_vect hit, double dist, t_node *node)
{
	node->hit_point = hit;
	node->obj = obj;
	node->dist = dist;
}

t_node	*hit_cercle(t_rayt *rt, t_obj *obj, t_node *node)
{
	double	b;
	double	c;
	t_vect	hit_point;
	double	dist;

	b = 2 * (rt->vec_dir.x * (rt->c_pos.x - obj->pos.x) + rt->vec_dir.y *
			(rt->c_pos.y - obj->pos.y) + rt->vec_dir.z * (rt->c_pos.z - obj->pos.z));
	c = (pow(rt->c_pos.x - obj->pos.x, 2) + pow(rt->c_pos.y - obj->pos.y, 2) +
			pow(rt->c_pos.z - obj->pos.z, 2)) - pow(obj->rayon, 2);
	rt->delta = pow(b, 2) - 4 * rt->a * c;
	if (rt->delta >= 0)
	{
		rt->delta = sqrt(rt->delta);
		rt->t1 = (-b + rt->delta) / 2 * rt->a;
		rt->t2 = (-b - rt->delta) / 2 * rt->a;
		rt->solut = rt->t1 > rt->t2 ? rt->t2 : rt->t1;
		hit_point = add(rt->c_pos, multiple_value(rt->vec_dir, rt->solut));
		dist = sqrt(pow(hit_point.x - rt->c_pos.x, 2) + pow(hit_point.y -
					rt->c_pos.y, 2) + pow(hit_point.z - rt->c_pos.z, 2));
		if (node->dist == -1 || node->dist > dist)
			update_node(obj, hit_point, dist, node);
	}
	return (node);
}

t_node	*ft_intersect(t_rayt *rt, t_obj *obj, t_node *node)
{
	rt->a = pow(rt->vec_dir.x, 2) + pow(rt->vec_dir.y, 2) +
		pow(rt->vec_dir.z, 2);
	node->dist = -1;
	while (obj)
	{
		if (obj->type == 1)
			node = hit_cercle(rt, obj, node);
		obj = obj->next;
	}
	return (node);
}

void	raytracing(t_rayt *rt, t_graph *gr, t_obj *obj)
{
	t_node	*node;
	t_vect	point;

	node = (t_node *)malloc(sizeof(t_node));
	rt->x_ind = rt->view_w / (double)gr->s_x;
	rt->y_ind = rt->view_h / (double)gr->s_y;
	gr->y = 0;
	while (gr->y < gr->s_y)
	{
		gr->x = 0;
		while (gr->x < gr->s_x)
		{
			point = substract(add(rt->up_left, multiple_value(rt->vec_right,
							rt->x_ind * gr->x)), multiple_value(rt->vec_up, rt->y_ind * gr->y));
			rt->vec_dir = normalize(substract(point, rt->c_pos));
			node = ft_intersect(rt, obj, node);
			if (node->dist != -1)
				ft_setpixel(gr, gr->x, gr->y, ft_light(node, rt, obj));
			gr->x++;
		}
		gr->y++;
	}
	free(node);
}

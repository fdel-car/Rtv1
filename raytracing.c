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

t_node	*hit_cercle(t_rayt *rt, t_obj *obj, t_node *node, t_vect from)
{
	double	b;
	double	c;
	t_vect	hit_point;
	double	dist;

	b = 2 * (rt->vec_dir.x * (from.x - obj->pos.x) + rt->vec_dir.y *
			(from.y - obj->pos.y) + rt->vec_dir.z * (from.z - obj->pos.z));
	c = (pow(from.x - obj->pos.x, 2) + pow(from.y - obj->pos.y, 2) +
			pow(from.z - obj->pos.z, 2)) - pow(obj->rayon, 2);
	rt->delta = pow(b, 2) - 4 * rt->a * c;
	if (rt->delta >= 0)
	{
		rt->delta = sqrt(rt->delta);
		rt->t1 = (-b + rt->delta) / 2 * rt->a;
		rt->t2 = (-b - rt->delta) / 2 * rt->a;
		rt->solut = rt->t1 > rt->t2 ? rt->t2 : rt->t1;
		if (rt->solut < 0)
			return (node);
		hit_point = add(from, multiple_value(rt->vec_dir, rt->solut));
		dist = sqrt(pow(hit_point.x - from.x, 2) + pow(hit_point.y -
					from.y, 2) + pow(hit_point.z - from.z, 2));
		if (node->dist == -1 || node->dist > dist)
			update_node(obj, hit_point, dist, node);
	}
	return (node);
}

t_node	*hit_plan(t_rayt *rt, t_obj *obj, t_node *node, t_vect from)
{
	t_vect	hit_point;
	double	dist;

	rt->solut = -((dot_product(obj->norm, from) + obj->cons) /
	dot_product(obj->norm, rt->vec_dir));
	if (rt->solut < 0)
		return (node);
	hit_point = add(from, multiple_value(rt->vec_dir, rt->solut));
	dist = sqrt(pow(hit_point.x - from.x, 2) + pow(hit_point.y -
				from.y, 2) + pow(hit_point.z - from.z, 2));
	if (node->dist == -1 || node->dist > dist)
		update_node(obj, hit_point, dist, node);
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
			node = hit_cercle(rt, obj, node, rt->c_pos);
		if (obj->type == 2)
			node = hit_plan(rt, obj, node, rt->c_pos);
		// if (obj->type == 3)
		// 	node = hit_cylinder(rt, obj, node, rt->c_pos);
		obj = obj->next;
	}
	return (node);
}

void	raytracing(t_rayt *rt, t_graph *gr, t_obj *obj)
{
	t_node			*node;
	t_vect			point;

	node = (t_node *)malloc(sizeof(t_node));
	rt->x_ind = rt->view_w / (double)gr->s_x;
	rt->y_ind = rt->view_h / (double)gr->s_y;
	gr->y = 0;
	while (gr->y < gr->s_y)
	{
		gr->x = 0;
		while (gr->x < gr->s_x)
		{
			point = subtract(add(rt->up_left, multiple_value(rt->vec_right,
			rt->x_ind * gr->x)), multiple_value(rt->vec_up, rt->y_ind * gr->y));
			rt->vec_dir = normalize(subtract(point, rt->c_pos));
			node = ft_intersect(rt, obj, node);
			if (node->dist != -1)
				ft_setpixel(gr, gr->x, gr->y,
				ft_light(node, rt, obj));
			gr->x++;
		}
		gr->y++;
	}
	free(node);
}

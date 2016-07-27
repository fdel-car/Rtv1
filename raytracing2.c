/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 14:05:10 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/27 14:05:16 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// t_node	*hit_cylinder(t_rayt *rt, t_obj *obj, t_node *node, t_vect from)
// {
// 	double	a;
// 	double	b;
// 	double	c;
// 	t_vect	hit_point;
// 	double	dist;
//
// 	a = pow(rt->vec_dir.x, 2) + pow(rt->vec_dir.z, 2);
// 	b = 2 * (rt->vec_dir.x * (from.x) + rt->vec_dir.z *
// 			(from.z));
// 	c = (pow(from.x, 2) + pow(from.z, 2)) - 1;
// 	rt->delta = pow(b, 2) - 4 * a * c;
// 	if (rt->delta >= 0)
// 	{
// 		rt->delta = sqrt(rt->delta);
// 		rt->t1 = (-b + rt->delta) / 2 * a;
// 		rt->t2 = (-b - rt->delta) / 2 * a;
// 		rt->solut = rt->t1 > rt->t2 ? rt->t2 : rt->t1;
// 		if (rt->solut < 0)
// 			return (node);
// 		hit_point = add(from, multiple_value(rt->vec_dir, rt->solut));
// 		dist = sqrt(pow(hit_point.x - from.x, 2) + pow(hit_point.y -
// 					from.y, 2) + pow(hit_point.z - from.z, 2));
// 		if (node->dist == -1 || node->dist > dist)
// 			update_node(obj, hit_point, dist, node);
// 	}
// 	return (node);
// }

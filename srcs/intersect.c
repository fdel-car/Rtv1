/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:33:06 by fdel-car          #+#    #+#             */
/*   Updated: 2016/08/21 14:33:10 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	update_ray(t_obj *obj, t_vect hit, float dist, t_ray *ray)
{
	ray->hit_point = hit;
	ray->obj = obj;
	ray->dist = dist;
}

t_ray	*hit_cercle(t_ray *ray, t_info *inf)
{
	t_vect	hit_point;
	float	dist;

	inf->b = 2.0 * (inf->dir.x * (inf->fr.x - (inf->obj)->pos.x) + inf->dir.y *
	(inf->fr.y - (inf->obj)->pos.y) + inf->dir.z * (inf->fr.z -
	(inf->obj)->pos.z));
	inf->c = (SQ(inf->fr.x - (inf->obj)->pos.x) + SQ(inf->fr.y -
	(inf->obj)->pos.y) +
	SQ(inf->fr.z - (inf->obj)->pos.z)) - SQ((inf->obj)->rayon);
	inf->delta = (inf->b * inf->b) - 4.0 * inf->a * inf->c;
	if (inf->delta >= 0)
	{
		inf->delta = sqrt(inf->delta);
		inf->t1 = (-inf->b + inf->delta) / (2.0 * inf->a);
		inf->t2 = (-inf->b - inf->delta) / (2.0 * inf->a);
		inf->solut = inf->t1 > inf->t2 ? inf->t2 : inf->t1;
		if (inf->solut < 0.0)
			return (ray);
		hit_point = add(inf->fr, multiple_value(inf->dir, inf->solut));
		dist = dist_p(hit_point, inf->fr);
		if (ray->dist == -1 || ray->dist > dist - EPSILON)
			update_ray(inf->obj, hit_point, dist, ray);
	}
	return (ray);
}

t_ray	*hit_plan(t_ray *ray, t_info *inf)
{
	t_vect	hit_point;
	double	dist;

	inf->solut = -((dotp_n((inf->obj)->norm, inf->fr) + (inf->obj)->cons) /
	dotp_n((inf->obj)->norm, inf->dir));
	if (inf->solut < 0)
		return (ray);
	hit_point = add(inf->fr, multiple_value(inf->dir, inf->solut));
	dist = dist_p(hit_point, inf->fr);
	if (ray->dist == -1 || ray->dist > dist - EPSILON)
		update_ray(inf->obj, hit_point, dist, ray);
	return (ray);
}

t_ray	*hit_cylinder(t_ray *ray, t_info *inf)
{
	float	a;
	float	dist;
	t_vect	hit_point;

	inf->tmp = subtract(inf->fr, (inf->obj)->pos);
	a = dotp_n(inf->dir, inf->dir) - (SQ(dotp_n(inf->dir, (inf->obj)->dir)));
	inf->b = 2.0 * (dotp_n(inf->dir, inf->tmp) - (dotp_n(inf->dir,
	(inf->obj)->dir) * dotp_n(inf->tmp, (inf->obj)->dir)));
	inf->c = dotp_n(inf->tmp, subtract(inf->fr, (inf->obj)->pos)) -
	(SQ(dotp_n(inf->tmp, (inf->obj)->dir))) - SQ((inf->obj)->rayon);
	inf->delta = SQ(inf->b) - 4.0 * a * inf->c;
	if (inf->delta >= 0.0)
	{
		inf->delta = sqrt(inf->delta);
		inf->t1 = (-inf->b + inf->delta) / (2.0 * a);
		inf->t2 = (-inf->b - inf->delta) / (2.0 * a);
		inf->solut = inf->t1 < inf->t2 ? inf->t1 : inf->t2;
		if (inf->solut < 0.0)
			return (ray);
		hit_point = add(inf->fr, multiple_value(inf->dir, inf->solut));
		dist = dist_p(hit_point, inf->fr);
		if (ray->dist == -1 || ray->dist > dist - EPSILON)
			update_ray(inf->obj, hit_point, dist, ray);
	}
	return (ray);
}

t_ray	*hit_cone(t_ray *ray, t_info *inf)
{
	float	dist;
	t_vect	hit_point;

	inf->tmp = subtract(inf->fr, (inf->obj)->pos);
	inf->a_cone = dotp_n(inf->dir, inf->dir) - ((1.0 + SQ((inf->obj)->alpha)) *
	SQ(dotp_n(inf->dir, (inf->obj)->dir)));
	inf->b = 2.0 * (dotp_n(inf->dir, inf->tmp) - ((1.0 + SQ((inf->obj)->alpha))
	* dotp_n(inf->dir, (inf->obj)->dir) * dotp_n(inf->tmp, (inf->obj)->dir)));
	inf->c = dotp_n(inf->tmp, inf->tmp) - ((1.0 + SQ((inf->obj)->alpha)) *
	SQ(dotp_n(inf->tmp, (inf->obj)->dir)));
	inf->delta = SQ(inf->b) - 4.0 * inf->a_cone * inf->c;
	if (inf->delta >= 0.0)
	{
		inf->delta = sqrt(inf->delta);
		inf->t1 = (-inf->b + inf->delta) / (2.0 * inf->a_cone);
		inf->t2 = (-inf->b - inf->delta) / (2.0 * inf->a_cone);
		inf->solut = inf->t1 < inf->t2 ? inf->t1 : inf->t2;
		if (inf->solut < 0.0)
			return (ray);
		hit_point = add(inf->fr, multiple_value(inf->dir, inf->solut));
		dist = dist_p(hit_point, inf->fr);
		if (ray->dist == -1 || ray->dist > dist - EPSILON)
			update_ray(inf->obj, hit_point, dist, ray);
	}
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:11:57 by fdel-car          #+#    #+#             */
/*   Updated: 2016/08/15 18:11:58 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	rot_any(t_vect u, t_vect a, float theta)
{
	float	c;
	float	s;
	float	t;
	t_vect	v;

	theta = theta * (2.0 * M_PI) / 360.0;
	c = cos(theta);
	s = sin(theta);
	t = 1 - c;
	v.x = (t * SQ(a.x) + c) * u.x + (t * a.x * a.y - s * a.z) * u.y +
	(t * a.x * a.z + s * a.y) * u.z;
	v.y = (t * a.x * a.y + s * a.z) * u.x + (t * SQ(a.y) + c) * u.y +
	(t * a.y * a.z - s * a.x) * u.z;
	v.z = (t * a.x * a.z - s * a.y) * u.x + (t * a.y * a.z + s * a.x) * u.y +
	(t * SQ(a.z) + c) * u.z;
	return (v);
}

float	dist_p(t_vect u, t_vect v)
{
	float dist;

	dist = sqrt(SQ(u.x - v.x) + SQ(u.y - v.y) + SQ(u.z - v.z));
	return (dist);
}

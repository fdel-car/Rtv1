/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:06:26 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/26 17:06:27 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	dotp_n(t_vect u, t_vect v)
{
	float ret;

	ret = (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
	return (ret);
}

t_vect	create_vect(float x, float y, float z)
{
	t_vect vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vect	rot_y(float theta, t_vect u)
{
	t_vect	v;

	theta = theta * (2.0 * M_PI) / 360.0;
	v.x = cos(theta) * u.x + sin(theta) * u.z;
	v.y = u.y;
	v.z = -sin(theta) * u.x + cos(theta) * u.z;
	return (v);
}

t_vect	rot_x(float theta, t_vect u)
{
	t_vect	v;

	theta = theta * (2.0 * M_PI) / 360.0;
	v.x = u.x;
	v.y = cos(theta) * u.y - sin(theta) * u.z;
	v.z = sin(theta) * u.y + cos(theta) * u.z;
	return (v);
}

t_vect	rot_z(float theta, t_vect u)
{
	t_vect	v;

	theta = theta * (2.0 * M_PI) / 360.0;
	v.x = cos(theta) * u.x - sin(theta) * u.y;
	v.y = sin(theta) * u.x + cos(theta) * u.y;
	v.z = u.z;
	return (v);
}

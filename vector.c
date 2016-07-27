/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:26:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/17 18:37:21 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	multiple(t_vect u, t_vect v)
{
	t_vect w;

	w.x = (u.y * v.z) - (u.z * v.y);
	w.y = (u.z * v.x) - (u.x * v.z);
	w.z = (u.x * v.y) - (u.y * v.x);
	return (w);
}

t_vect	multiple_value(t_vect u, double value)
{
	t_vect w;

	w.x = u.x * value;
	w.y = u.y * value;
	w.z = u.z * value;
	return (w);
}

t_vect	subtract(t_vect u, t_vect v)
{
	t_vect w;

	w.x = u.x - v.x;
	w.y = u.y - v.y;
	w.z = u.z - v.z;
	return (w);
}

t_vect	add(t_vect u, t_vect v)
{
	t_vect w;

	w.x = u.x + v.x;
	w.y = u.y + v.y;
	w.z = u.z + v.z;
	return (w);
}

t_vect	normalize(t_vect u)
{
	t_vect w;
	double length;

	length = sqrt((u.x * u.x) + (u.y * u.y) + (u.z * u.z));
	w.x = u.x / length;
	w.y = u.y / length;
	w.z = u.z / length;
	return (w);
}

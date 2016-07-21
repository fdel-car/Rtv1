/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:09:26 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/21 20:29:46 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	multiple_color(t_color color, double value)
{
	t_color rgb;

	rgb.r = color.r * value;
	if (rgb.r > 255)
		rgb.r = 255;
	rgb.g = color.g * value;
	if (rgb.g > 255)
		rgb.g = 255;
	rgb.b = color.b * value;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

t_color	add_color(t_color u, t_color v)
{
	t_color rgb;

	rgb.r = u.r + v.r;
	if (rgb.r > 255)
		rgb.r = 255;
	rgb.g = u.g + v.g;
	if (rgb.g > 255)
		rgb.g = 255;
	rgb.b = u.b + v.b;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

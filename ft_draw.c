/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:26:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/06/02 18:25:37 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_setpixel(t_data *data, int x, int y, t_color color)
{
	int				i;

	if (x > data->s_x || y > data->s_y || x < 0 || y < 0)
		return ;
	i = y * data->sizeline + x * data->bpp / 8;
	data->disp[i + 2] = color.r;
	data->disp[i + 1] = color.g;
	data->disp[i] = color.b;
}

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

void	ft_setpixel(t_graph *gr, int x, int y, t_color color)
{
	int				i;

	if (x > gr->s_x || y > gr->s_y || x < 0 || y < 0)
		return ;
	i = y * gr->sizeline + x * gr->bpp / 8;
	gr->disp[i] = color.b;
	gr->disp[i + 1] = color.g;
	gr->disp[i + 2] = color.r;
}

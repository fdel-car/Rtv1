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

void	ft_setpixel(t_graph *gr, int x, int y, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				i;

	if (x > gr->s_x || y > gr->s_y || x < 0 || y < 0)
		return ;
	i = y * gr->sizeline + x * gr->bpp / 8;
	r = (color & 0xFF);
	g = ((color & 0xFF00) >> 8);
	b = ((color & 0xFF0000) >> 16);
	gr->disp[i] = r;
	gr->disp[i + 1] = g;
	gr->disp[i + 2] = b;
}

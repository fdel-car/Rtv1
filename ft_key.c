/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:18:18 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/26 15:18:19 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_close(void)
{
	exit(0);
}

int		ft_key(int keycode, t_glob *gl)
{
	if (keycode == 53)
		ft_close();
	if (keycode == 13)
		(gl->rt)->c_pos.z = (gl->rt)->c_pos.z + 1;
	if (keycode == 1)
		(gl->rt)->c_pos.z = (gl->rt)->c_pos.z - 1;
	if (keycode == 0)
		(gl->rt)->c_pos.x = (gl->rt)->c_pos.x - 1;
	if (keycode == 2)
		(gl->rt)->c_pos.x = (gl->rt)->c_pos.x + 1;
	if (keycode == 256)
		(gl->rt)->c_pos.y = (gl->rt)->c_pos.y - 1;
	if (keycode == 49)
		(gl->rt)->c_pos.y = (gl->rt)->c_pos.y + 1;
	ft_rt(gl);
	return (0);
}

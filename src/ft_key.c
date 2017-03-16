/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 16:54:03 by fdel-car          #+#    #+#             */
/*   Updated: 2016/08/13 16:54:13 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_close(t_data *data)
{
	t_obj *tmp;

	while (data->obj)
	{
		tmp = (data->obj)->next;
		free(data->obj);
		data->obj = tmp;
	}
	exit(0);
}

void	move_cam(int keycode, t_data *data)
{
	if (keycode == 13)
		data->cam_p = add(data->cam_p, data->init_dir);
	if (keycode == 1)
		data->cam_p = subtract(data->cam_p, data->init_dir);
	if (keycode == 2)
		data->cam_p = add(data->cam_p, rot_y(90, data->init_dir));
	if (keycode == 0)
		data->cam_p = subtract(data->cam_p, rot_y(90, data->init_dir));
	if (keycode == 256)
		data->cam_p = add(data->cam_p, rot_any(data->init_dir, data->a_x, 90));
	if (keycode == 49)
		data->cam_p = subtract(data->cam_p,
		rot_any(data->init_dir, data->a_x, 90));
}

void	rot_cam(int keycode, t_data *data)
{
	if (keycode == 123)
	{
		data->init_dir = rot_y(-10, data->init_dir);
		data->a_x = rot_y(-10, data->a_x);
	}
	if (keycode == 124)
	{
		data->init_dir = rot_y(10, data->init_dir);
		data->a_x = rot_y(10, data->a_x);
	}
}

int		key_handle(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_close(data);
	move_cam(keycode, data);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		rot_cam(keycode, data);
	build_img(*data);
	return (0);
}

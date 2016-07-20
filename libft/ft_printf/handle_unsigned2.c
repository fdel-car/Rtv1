/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:34:47 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:42:15 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_noulflag(va_list ap, t_print *gl)
{
	unsigned long int	u;
	int					space;
	int					temp;

	gl->i = 0;
	u = va_arg(ap, unsigned long int);
	space = ft_char_uns(u);
	temp = space;
	ft_putstr(gl->s);
	if (gl->p > space)
	{
		while (gl->larg-- > gl->p && gl->i++ < 2147483647)
			ft_putchar(gl->c);
		temp = gl->p;
	}
	else
		while (gl->larg-- > space && gl->i++ < 2147483647)
			ft_putchar(gl->c);
	while (gl->p-- > space)
		ft_putchar('0');
	space = temp;
	ft_putunbr(u);
	return (space + ft_strlen(gl->s) + gl->i);
}

int		ft_flag_unsl(char const *fl, va_list ap, t_print *gl)
{
	unsigned long int u;

	if (ft_unload_fl(fl, gl) < 0)
		return (-1);
	if (gl->fl_right == 1)
	{
		ft_putstr(gl->s);
		u = va_arg(ap, unsigned long int);
		gl->space = ft_char_uns(u);
		while (gl->p > gl->space)
		{
			ft_putchar('0');
			gl->space++;
		}
		ft_putunbr(u);
		while (gl->larg-- > gl->space && gl->i++ < 2147483647)
			ft_putchar(gl->c);
		return (gl->space + ft_strlen(gl->s) + gl->i);
	}
	else
		return (ft_noulflag(ap, gl));
}

int		ft_nouflag(va_list ap, t_print *gl)
{
	unsigned int	u;

	gl->i = 0;
	u = va_arg(ap, unsigned int);
	gl->space = ft_char_uns(u);
	gl->temp = gl->space;
	gl->temp2 = gl->p;
	ft_putstr(gl->s);
	if (gl->p > gl->space)
	{
		while (gl->larg-- > gl->p && gl->i++ < 2147483647)
			ft_putchar(gl->c);
		gl->temp = gl->p;
	}
	else
		while (gl->larg-- > gl->space && gl->i++ < 2147483647)
			ft_putchar(gl->c);
	while (gl->p-- > gl->space)
		ft_putchar('0');
	gl->space = gl->temp;
	if (gl->temp2 == 0 && u == 0)
		gl->space--;
	else
		ft_putunbr(u);
	return (gl->space + ft_strlen(gl->s) + gl->i);
}

int		ft_flag_uns(char const *fl, va_list ap, t_print *gl)
{
	unsigned int u;

	if (ft_unload_fl(fl, gl) < 0)
		return (-1);
	if (gl->fl_right == 1)
	{
		ft_putstr(gl->s);
		u = va_arg(ap, unsigned int);
		gl->space = ft_char_uns(u);
		while (gl->p > gl->space)
		{
			ft_putchar('0');
			gl->space++;
		}
		ft_putunbr(u);
		while (gl->larg-- > gl->space && gl->i++ < 2147483647)
			ft_putchar(gl->c);
		return (gl->space + ft_strlen(gl->s) + gl->i);
	}
	else
		return (ft_nouflag(ap, gl));
}

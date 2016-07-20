/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:49:06 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:35:23 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_hexa_flag(char const *fl, va_list ap, t_print *gl, char t)
{
	unsigned long long int	x;
	char					*str;

	str = NULL;
	if (ft_unload_fl_hex(fl, gl) < 0)
		return (-1);
	if (gl->fl_right == 1)
	{
		if (t == 'v' || t == 'V')
			x = va_arg(ap, unsigned long long int);
		if (t == 'l' || t == 'L')
			x = va_arg(ap, unsigned long int);
		if (t == 'x' || t == 'X')
			x = va_arg(ap, unsigned int);
		if (t == 's' || t == 'S')
			x = (unsigned short)va_arg(ap, unsigned int);
		if (t == 'c' || t == 'C')
			x = (unsigned char)va_arg(ap, unsigned int);
		return (ft_unload_hex3(gl, str, x, t));
	}
	return (ft_nohflag(ap, gl, t));
}

int		ft_hexa_short(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h')
		return (ft_hexa_char(fl, ap, gl));
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->p = ft_precision_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == '.')
	{
		gl->p = 0;
		gl->f++;
	}
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->larg = ft_width_str(fl, ap, gl);
	if (gl->inv == 2)
		ft_swap(&gl->p, &gl->larg);
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_hexa_flag(fl, ap, gl, 's');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_hexa_long_long(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	while (fl[gl->l - gl->f] == 'l' || fl[gl->l - gl->f] == 'z' ||
			fl[gl->l - gl->f] == 'j')
		gl->f++;
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->p = ft_precision_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == '.')
		gl->f++;
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->larg = ft_width_str(fl, ap, gl);
	if (gl->inv == 2)
		ft_swap(&gl->p, &gl->larg);
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_hexa_flag(fl, ap, gl, 'v');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_hexa_long(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l' || fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_hexa_long_long(fl, ap, gl));
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->p = ft_precision_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == '.')
		gl->f++;
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->larg = ft_width_str(fl, ap, gl);
	if (gl->inv == 2)
		ft_swap(&gl->p, &gl->larg);
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_hexa_flag(fl, ap, gl, 'l');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_hexa(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_hexa_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'z' || fl[gl->l - gl->f] == 'j')
		return (ft_hexa_long_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'h')
		return (ft_hexa_short(fl, ap, gl));
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->p = ft_precision_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == '.')
	{
		gl->p = 0;
		gl->f++;
	}
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->larg = ft_width_str(fl, ap, gl);
	if (gl->inv == 2)
		ft_swap(&gl->p, &gl->larg);
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' || fl[gl->l -
		gl->f] == '-' || fl[gl->l - gl->f] == '+' || fl[gl->l - gl->f] == '%')
		gl->flag = ft_hexa_flag(fl, ap, gl, 'x');
	ft_strclr(gl->s);
	return (gl->flag);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:49:06 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:40:46 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_octal_flag(char const *fl, va_list ap, t_print *gl, char t)
{
	unsigned long long int	o;
	char					*str;

	str = NULL;
	if (ft_unload_fl(fl, gl) < 0)
		return (-1);
	if (gl->fl_right == 1)
	{
		if (t == 'L')
			o = va_arg(ap, unsigned long long int);
		if (t == 'l')
			o = va_arg(ap, unsigned long int);
		if (t == 'o')
			o = va_arg(ap, unsigned int);
		if (t == 's')
			o = (unsigned short)va_arg(ap, unsigned int);
		if (t == 'c')
			o = (unsigned char)va_arg(ap, unsigned int);
		return (ft_unload_oct3(gl, str, o));
	}
	return (ft_nooflag(ap, gl, t));
}

int		ft_octal_short(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h')
		return (ft_octal_char(fl, ap, gl));
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
		gl->flag = ft_octal_flag(fl, ap, gl, 's');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_octal_long_long(char const *fl, va_list ap, t_print *gl)
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
		gl->flag = ft_octal_flag(fl, ap, gl, 'L');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_octal_long(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l' || fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h' || fl[gl->l - gl->f] == 'j' ||
		fl[gl->l - gl->f] == 'z')
		gl->f++;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_octal_long_long(fl, ap, gl));
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
		gl->flag = ft_octal_flag(fl, ap, gl, 'l');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_octal(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_octal_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'z' || fl[gl->l - gl->f] == 'j')
		return (ft_octal_long_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'h')
		return (ft_octal_short(fl, ap, gl));
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
		gl->flag = ft_octal_flag(fl, ap, gl, 'o');
	ft_strclr(gl->s);
	return (gl->flag);
}

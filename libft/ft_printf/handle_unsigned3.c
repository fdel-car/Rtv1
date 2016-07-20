/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:07:48 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:42:24 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_unss(char const *fl, va_list ap, t_print *gl)
{
	while (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '#' || fl[gl->l - gl->f] == '-' ||
			fl[gl->l - gl->f] == '0')
	{
		if (fl[gl->l - gl->f] == '-')
			gl->fl_right = 1;
		if (fl[gl->l - gl->f] == '0')
			gl->c = '0';
		gl->f++;
	}
	if (fl[gl->l - gl->f] != '%')
		return (-1);
	if (gl->fl_right == 1)
		return (ft_unload_unss(gl, ap));
	else
		return (ft_nousflag(ap, gl));
}

int		ft_uns_short(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h')
		return (ft_uns_char(fl, ap, gl));
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
		gl->flag = ft_flag_unss(fl, ap, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_unload_uns(t_print *gl, va_list ap)
{
	unsigned long long u;

	ft_putstr(gl->s);
	u = va_arg(ap, unsigned long long int);
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

int		ft_unload_fl(char const *fl, t_print *gl)
{
	while (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '#' || fl[gl->l - gl->f] == '-' ||
			fl[gl->l - gl->f] == '0')
	{
		if (fl[gl->l - gl->f] == '-')
			gl->fl_right = 1;
		if (fl[gl->l - gl->f] == '0')
			gl->c = '0';
		if (fl[gl->l - gl->f] == '#')
			gl->hash = 1;
		gl->f++;
	}
	if (fl[gl->l - gl->f] != '%')
		return (-1);
	return (0);
}

int		ft_unload_fl_hex(char const *fl, t_print *gl)
{
	while (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '#' || fl[gl->l - gl->f] == '-' ||
			fl[gl->l - gl->f] == '0')
	{
		if (fl[gl->l - gl->f] == '-')
			gl->fl_right = 1;
		if (fl[gl->l - gl->f] == '0')
			gl->c = '0';
		if (fl[gl->l - gl->f] == '#')
			gl->hash = 2;
		gl->f++;
	}
	if (fl[gl->l - gl->f] != '%')
		return (-1);
	return (0);
}

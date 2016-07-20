/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:57:06 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:34:18 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nocflag(va_list ap, t_print *gl, int lc)
{
	int		c;
	int		l;

	gl->i = 0;
	c = va_arg(ap, int);
	ft_putstr(gl->s);
	gl->larg--;
	while (gl->larg-- > 0 && gl->i++ < 2147483647)
		ft_putchar(gl->c);
	l = ft_putwchar(c, lc);
	return (l + ft_strlen(gl->s) + gl->i);
}

int		ft_flag_char(char const *fl, va_list ap, t_print *gl, int lc)
{
	int c;
	int l;

	gl->i = 0;
	if (ft_unload_fl(fl, gl) < 0)
		return (-1);
	if (gl->fl_right == 1)
	{
		ft_putstr(gl->s);
		c = va_arg(ap, int);
		l = ft_putwchar(c, lc);
		gl->larg--;
		while (gl->larg-- > 0 && gl->i++ < 2147483647)
			ft_putchar(gl->c);
		return (l + ft_strlen(gl->s) + gl->i);
	}
	else
		return (ft_nocflag(ap, gl, lc));
}

int		ft_widechar(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	if (fl[gl->l - gl->f] == 'l')
		gl->f++;
	if (fl[gl->l - gl->f] == '.')
		gl->f++;
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->p = ft_precision_str(fl, ap, gl);
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->larg = ft_width_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_flag_char(fl, ap, gl, 1);
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_char(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_widechar(fl, ap, gl));
	if (fl[gl->l - gl->f] == '.')
		gl->f++;
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->p = ft_precision_str(fl, ap, gl);
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->larg = ft_width_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_flag_char(fl, ap, gl, 0);
	ft_strclr(gl->s);
	return (gl->flag);
}

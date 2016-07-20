/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:03:23 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:41:47 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

int		ft_wstrlen(wchar_t const *s)
{
	int o;

	o = 0;
	while (*s)
	{
		o += ft_check_uni(*s);
		s++;
	}
	return (o);
}

int		ft_nowflag(va_list ap, t_print *gl)
{
	int		temp;
	wchar_t	*str;
	int		c;

	gl->i = 0;
	str = va_arg(ap, wchar_t *);
	if (!str)
		str = L"(null)";
	temp = gl->p;
	ft_putstr(gl->s);
	if (gl->p >= 0 && gl->p <= (int)ft_wstrlen(str))
	{
		gl->larg -= gl->p;
		c = ft_check_uni(str[0]);
		if (c > 1 && gl->larg > 0 && gl->p > 0)
			gl->larg++;
		if (c > gl->p)
			gl->larg += gl->p;
	}
	else
		gl->larg -= ft_wstrlen(str);
	while (gl->larg-- > 0 && gl->i++ < 2147483647)
		ft_putchar(gl->c);
	gl->p = ft_putwstr(str, temp);
	return (gl->p + ft_strlen(gl->s) + gl->i);
}

int		ft_flags_wide(char const *fl, va_list ap, t_print *gl)
{
	gl->i = 0;
	ft_unload_fl(fl, gl);
	if (gl->fl_right == 1)
	{
		ft_putstr(gl->s);
		gl->wide = va_arg(ap, wchar_t *);
		if (!gl->wide)
			gl->wide = L"(null)";
		gl->p = ft_putwstr(gl->wide, gl->p);
		if (gl->p != -2 && gl->p != -1 && gl->p <= (int)ft_wstrlen(gl->wide))
			gl->larg -= gl->p;
		else
			gl->larg -= ft_wstrlen(gl->wide);
		while (gl->larg-- > 0 && gl->i++ < 2147483647)
			ft_putchar(' ');
		return (gl->p + ft_strlen(gl->s) + gl->i);
	}
	else
		return (ft_nowflag(ap, gl));
}

int		ft_widestring(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	if (gl->s_wide == 0)
		gl->f++;
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->p = ft_precision_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == '.')
	{
		gl->p = 0;
		gl->f++;
	}
	if (ft_isdigit(fl[gl->l - gl->f]) || fl[gl->l - gl->f] == '*')
		gl->larg = ft_width_str(fl, ap, gl);
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_flags_wide(fl, ap, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_string(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	if (fl[gl->l - gl->f] == 'l')
	{
		gl->s_wide = 0;
		return (ft_widestring(fl, ap, gl));
	}
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
		gl->flag = ft_flags_str(fl, ap, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

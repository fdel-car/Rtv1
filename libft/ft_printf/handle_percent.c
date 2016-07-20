/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:18:21 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:41:28 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unload_percent(t_print *gl)
{
	ft_putstr(gl->s);
	ft_putchar('%');
	while (gl->larg > 1 && gl->i++ < 2147483647)
	{
		ft_putchar(' ');
		gl->larg--;
	}
	return (1 + gl->i + ft_strlen(gl->s));
}

int		nopercentflag(t_print *gl)
{
	ft_putstr(gl->s);
	while (gl->larg > 1 && gl->i++ < 2147483647)
	{
		ft_putchar(gl->c);
		gl->larg--;
	}
	ft_putchar('%');
	return (1 + gl->i + ft_strlen(gl->s));
}

int		ft_flag_percent(char const *fl, t_print *gl)
{
	while (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '#' || fl[gl->l - gl->f] == '0' ||
			fl[gl->l - gl->f] == '-')
	{
		if (fl[gl->l - gl->f] == '+')
			gl->sign = 1;
		if (fl[gl->l - gl->f] == '0')
			gl->c = '0';
		if (fl[gl->l - gl->f] == ' ')
			gl->fl_s = 1;
		if (fl[gl->l - gl->f] == '-')
			gl->fl_right = 1;
		gl->f++;
	}
	if (fl[gl->l - gl->f] != '%')
		return (-1);
	if (gl->fl_right == 1)
		return (unload_percent(gl));
	else
		return (nopercentflag(gl));
}

int		ft_percent(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
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
		gl->flag = ft_flag_percent(fl, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 14:19:03 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:41:59 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int		ft_precision_str(char const *fl, va_list ap, t_print *gl)
{
	gl->temp = gl->f;
	if (ft_isdigit(fl[gl->l - gl->f]))
	{
		while (ft_isdigit(fl[gl->l - gl->f]))
			gl->f++;
		if (fl[gl->l - gl->f] != '.')
		{
			gl->f = gl->temp;
			return (-1);
		}
		return (ft_atoi(fl + gl->l - ++gl->f + 2));
	}
	else
	{
		if (fl[gl->l - ++gl->f] != '.')
		{
			gl->f = gl->temp;
			return (-1);
		}
		gl->p = va_arg(ap, int);
		gl->p = gl->p < 0 ? -1 : gl->p;
		gl->inv++;
		gl->f++;
		return (gl->p);
	}
}

int		ft_width_str(char const *fl, va_list ap, t_print *gl)
{
	int temp;

	temp = gl->f;
	if (ft_isdigit(fl[gl->l - gl->f]))
	{
		while (ft_isdigit(fl[gl->l - gl->f]))
			gl->f++;
		if (fl[gl->l - gl->f + 1] == '0')
		{
			gl->c = '0';
			return (ft_atoi(fl + gl->l - gl->f + 2));
		}
		return (ft_atoi(fl + gl->l - gl->f + 1));
	}
	else
	{
		gl->larg = va_arg(ap, int);
		if (gl->larg < 0)
			gl->fl_right = 1;
		if (gl->larg < 0)
			gl->larg = -gl->larg;
		gl->inv++;
		gl->f++;
		return (gl->larg);
	}
}

int		ft_noflag(va_list ap, t_print *gl)
{
	int		temp;
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr(gl->s);
	temp = gl->p;
	if (gl->p != -2 && gl->p != -1 && gl->p <= (int)ft_strlen(str))
		gl->larg -= gl->p;
	else
		gl->larg -= ft_strlen(str);
	while (gl->larg-- > 0)
	{
		i++;
		ft_putchar(gl->c);
	}
	gl->p = ft_putnstr(str, temp);
	return (gl->p + ft_strlen(gl->s) + i);
}

int		ft_flags_str(const char *fl, va_list ap, t_print *gl)
{
	gl->i = 0;
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '+' ||
		fl[gl->l - gl->f] == '#')
		gl->f++;
	if (fl[gl->l - gl->f] != '%')
		if (fl[gl->l - gl->f - 1] != '%')
			return (-1);
	if (fl[gl->l - gl->f] == '-')
	{
		ft_putstr(gl->s);
		gl->str = va_arg(ap, char *);
		if (gl->str == NULL)
			gl->str = "(null)";
		gl->p = ft_putnstr(gl->str, gl->p);
		if (gl->p != -2 && gl->p != -1 && gl->p <= (int)ft_strlen(gl->str))
			gl->larg -= gl->p;
		else
			gl->larg -= ft_strlen(gl->str);
		while (gl->larg-- > 0 && gl->i++ < 2147483647)
			ft_putchar(' ');
		return (gl->p + ft_strlen(gl->s) + gl->i);
	}
	else
		return (ft_noflag(ap, gl));
}

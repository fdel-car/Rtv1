/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:34:47 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:40:30 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unload2(t_print *gl, char t, long long int i)
{
	if (gl->p < 0)
	{
		if (gl->c == ' ')
		{
			if (ft_signfl(gl, i) || i < 0 || (gl->fl_s == 1 && i >= 0))
			{
				if (ft_signfl(gl, i))
					ft_putchar('+');
				if (gl->fl_s == 1 && i >= 0 && !ft_signfl(gl, i))
					ft_putchar(' ');
				if (i < 0)
				{
					ft_putchar('-');
					i = -i;
				}
				gl->neg = 1;
			}
		}
	}
	return (unload3(gl, t, i));
}

int		unload(t_print *gl, char t, long long int i)
{
	if (gl->p < 0)
	{
		if (gl->c == '0')
		{
			if (ft_signfl(gl, i) || i < 0 || (gl->fl_s == 1 && i >= 0))
			{
				if (ft_signfl(gl, i))
					ft_putchar('+');
				if (gl->fl_s == 1 && i >= 0 && !ft_signfl(gl, i))
					ft_putchar(' ');
				if (i < 0)
				{
					ft_putchar('-');
					i = -i;
				}
				gl->neg = 1;
			}
		}
		while (gl->larg > gl->space && gl->i++ < 2147483647)
		{
			gl->larg--;
			ft_putchar(gl->c);
		}
	}
	return (unload2(gl, t, i));
}

int		ft_noiflag(va_list ap, t_print *gl, char t)
{
	long long int	i;

	gl->i = 0;
	if (t == 'i')
		i = va_arg(ap, int);
	if (t == 'l')
		i = va_arg(ap, long int);
	if (t == 'L')
		i = va_arg(ap, long long int);
	if (t == 's')
		i = (short)va_arg(ap, int);
	if (t == 'c')
		i = (char)va_arg(ap, int);
	ft_putstr(gl->s);
	gl->temp = gl->larg;
	gl->space = ft_char_int(i);
	if (ft_signfl(gl, i) || i < 0 || (gl->fl_s == 1 && i >= 0))
		gl->larg--;
	return (unload(gl, t, i));
}

int		ft_flag_int(char const *fl, va_list ap, t_print *gl, char t)
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
		return (unload5(gl, t, ap));
	else
		return (ft_noiflag(ap, gl, t));
}

int		ft_int_short(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h')
		return (ft_int_char(fl, ap, gl));
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
		gl->flag = ft_flag_int(fl, ap, gl, 's');
	ft_strclr(gl->s);
	return (gl->flag);
}

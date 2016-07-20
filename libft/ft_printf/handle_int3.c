/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 23:34:47 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:40:38 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unload6(t_print *gl, char t, long long int i)
{
	if (ft_signfl(gl, i) || i < 0 || (gl->fl_s == 1 && i >= 0))
	{
		gl->larg--;
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
	while (gl->p > gl->space)
	{
		ft_putchar('0');
		gl->space++;
	}
	return (unload7(gl, t, i));
}

int		unload5(t_print *gl, char t, va_list ap)
{
	long long int i;

	ft_putstr(gl->s);
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
	gl->space = ft_char_int(i);
	return (unload6(gl, t, i));
}

int		unload4(t_print *gl, char t, long long int i)
{
	if (i == 0 && gl->p == 0)
	{
		if (gl->temp > 0)
			ft_putchar(' ');
		else
			gl->space--;
	}
	else
	{
		if (t == 'i')
			ft_putunbr((unsigned int)i);
		if (t == 'l')
			ft_putunbr((unsigned long int)i);
		if (t == 'L')
			ft_putunbr((unsigned long long int)i);
		if (t == 's')
			ft_putunbr((unsigned short)i);
		if (t == 'c')
			ft_putunbr((unsigned char)i);
	}
	return (gl->space + ft_strlen(gl->s) + gl->i + gl->neg);
}

int		unload3(t_print *gl, char t, long long int i)
{
	if (gl->p >= 0)
	{
		while (gl->larg > gl->p && gl->larg-- > gl->space &&
				gl->i++ < 2147483647)
			ft_putchar(' ');
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
	while (gl->p > gl->space)
	{
		ft_putchar('0');
		gl->space++;
	}
	return (unload4(gl, t, i));
}

int		ft_int_char(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h')
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
		gl->flag = ft_flag_int(fl, ap, gl, 'c');
	ft_strclr(gl->s);
	return (gl->flag);
}

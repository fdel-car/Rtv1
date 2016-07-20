/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 17:20:17 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:40:18 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unload7(t_print *gl, char t, long long int i)
{
	if (i == 0 && gl->p == 0)
		ft_putchar(' ');
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
	while (gl->larg-- > gl->space && gl->i++ < 2147483647)
		ft_putchar(' ');
	return (gl->space + ft_strlen(gl->s) + gl->i + gl->neg);
}

int		ft_int_long_long(char const *fl, va_list ap, t_print *gl)
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
		gl->flag = ft_flag_int(fl, ap, gl, 'L');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_int_long(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l' || fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h' || fl[gl->l - gl->f] == 'j' ||
		fl[gl->l - gl->f] == 'z')
		gl->f++;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_int_long_long(fl, ap, gl));
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
		gl->flag = ft_flag_int(fl, ap, gl, 'l');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_int(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_int_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'z' || fl[gl->l - gl->f] == 'j')
		return (ft_int_long_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'h')
		return (ft_int_short(fl, ap, gl));
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
		gl->flag = ft_flag_int(fl, ap, gl, 'i');
	ft_strclr(gl->s);
	return (gl->flag);
}

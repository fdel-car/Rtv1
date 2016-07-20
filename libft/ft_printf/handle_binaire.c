/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binaire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:49:06 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:33:53 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unload_binaire(t_print *gl, unsigned long long int b, char t)
{
	char *str;

	ft_putstr(gl->s);
	str = ft_itoa_base(b, 2);
	if (gl->p > 0)
		return (-1);
	if (gl->c == '0')
		return (-1);
	if (t == 'b' && gl->hash == 2)
		ft_putstr("0b");
	if (t == 'B' && gl->hash == 2)
		ft_putstr("0B");
	if (gl->hash == 2)
		gl->i = gl->i + 2;
	ft_putstr(str);
	free(str);
	if (gl->larg < 0)
		gl->larg = 0;
	while (gl->larg-- > (int)ft_strlen(str) + gl->hash && gl->i++ < 2147483647)
		ft_putchar(' ');
	return (ft_strlen(gl->s) + ft_strlen(str) + gl->i);
}

int		nobflag(va_list ap, t_print *gl, char t)
{
	unsigned long long int	b;
	char					*str;

	ft_putstr(gl->s);
	b = va_arg(ap, unsigned long long int);
	str = ft_itoa_base(b, 2);
	if (gl->p > 0)
		return (-1);
	if (gl->c == '0')
		return (-1);
	if (gl->larg < 0)
		gl->larg = 0;
	while (gl->larg-- > (int)(ft_strlen(str) + gl->hash) &&
			gl->i++ < 2147483647)
		ft_putchar(' ');
	if (t == 'b' && gl->hash == 2)
		ft_putstr("0b");
	if (t == 'B' && gl->hash == 2)
		ft_putstr("0B");
	if (gl->hash == 2)
		gl->i = gl->i + 2;
	ft_putstr(str);
	free(str);
	return (ft_strlen(gl->s) + ft_strlen(str) + gl->i);
}

int		ft_binaire_flag(char const *fl, va_list ap, t_print *gl, char t)
{
	unsigned long long int	b;

	if (ft_unload_fl_hex(fl, gl) < 0)
		return (-1);
	if (gl->fl_right == 1)
	{
		ft_putstr(gl->s);
		b = va_arg(ap, unsigned long long int);
		return (ft_unload_binaire(gl, b, t));
	}
	return (nobflag(ap, gl, t));
}

int		ft_binaire_maj(char const *fl, va_list ap, t_print *gl)
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
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_binaire_flag(fl, ap, gl, 'B');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_binaire(char const *fl, va_list ap, t_print *gl)
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
	if (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '#' ||
			fl[gl->l - gl->f] == '-' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '%')
		gl->flag = ft_binaire_flag(fl, ap, gl, 'b');
	ft_strclr(gl->s);
	return (gl->flag);
}

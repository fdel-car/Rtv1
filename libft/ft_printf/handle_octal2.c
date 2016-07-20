/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 19:30:08 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:41:17 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unload_oct3(t_print *gl, char *str, unsigned long long int o)
{
	str = ft_itoa_base(o, 8);
	gl->space = ft_strlen(str);
	ft_putstr(gl->s);
	if (gl->hash == 1 && o != 0)
	{
		gl->hash = 0;
		ft_putchar('0');
		gl->space++;
	}
	while (gl->p > gl->space)
	{
		ft_putchar('0');
		gl->space++;
	}
	ft_putstr(str);
	free(str);
	while (gl->larg-- > gl->space && gl->i < 2147483647)
	{
		ft_putchar(' ');
		gl->i++;
	}
	return (gl->space + gl->i + ft_strlen(gl->s));
}

void	ft_unload_oct2(t_print *gl, char *str, unsigned long long int o)
{
	while (gl->larg > (gl->space + gl->hash) && gl->i < 2147483647
			&& gl->larg > gl->p)
	{
		gl->i++;
		ft_putchar(' ');
		gl->larg--;
	}
	if (gl->hash == 1)
		ft_putchar('0');
	if (gl->hash == 1)
		gl->space++;
	while (gl->p > gl->space && gl->space++ < 2147483647)
		ft_putchar('0');
	if (gl->p == 0 && o == 0)
	{
		if (gl->larg >= 0)
			ft_putchar(' ');
		else
			gl->space--;
	}
	else
	{
		ft_putstr(str);
		free(str);
	}
}

int		ft_unload_oct(t_print *gl, char *str, unsigned long long int o)
{
	str = ft_itoa_base(o, 8);
	gl->space = ft_strlen(str);
	ft_putstr(gl->s);
	if (gl->p < 0)
	{
		while (gl->larg > (gl->space + gl->hash) && gl->i < 2147483647)
		{
			ft_putchar(gl->c);
			gl->larg--;
			gl->i++;
		}
		if (gl->hash == 1 && o != 0)
		{
			ft_putchar('0');
			gl->space++;
		}
		ft_putstr(str);
		free(str);
	}
	if (gl->p >= 0)
		ft_unload_oct2(gl, str, o);
	return (gl->space + gl->i + ft_strlen(gl->s));
}

int		ft_nooflag(va_list ap, t_print *gl, char t)
{
	char					*str;
	unsigned long long int	o;

	str = NULL;
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
	return (ft_unload_oct(gl, str, o));
}

int		ft_octal_char(char const *fl, va_list ap, t_print *gl)
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
		gl->flag = ft_octal_flag(fl, ap, gl, 'c');
	ft_strclr(gl->s);
	return (gl->flag);
}

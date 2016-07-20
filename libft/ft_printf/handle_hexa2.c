/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 19:30:08 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:35:37 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unload_hex3(t_print *gl, char *str, unsigned long long int x, char t)
{
	if (x == 0)
	{
		ft_putstr(gl->s);
		while (gl->p-- != 0)
		{
			ft_putchar('0');
			gl->larg--;
			gl->i++;
			if (gl->p < 0)
				break ;
		}
		while (gl->larg-- > 0 && gl->i++ < 2147483647)
			ft_putchar(' ');
		return (gl->i + ft_strlen(gl->s));
	}
	if (!ft_isupper(t))
		str = ft_itoa_base(x, 16);
	else
		str = ft_itoa_base_maj(x, 16);
	gl->space = ft_strlen(str);
	ft_putstr(gl->s);
	return (unload_hex(gl, str, x, t));
}

void	ft_unload_hex2(t_print *gl, char *str, unsigned long long int x, char t)
{
	while (gl->larg > (gl->space + gl->hash) && gl->i < 2147483647
			&& gl->larg > gl->p)
	{
		gl->i++;
		ft_putchar(' ');
		gl->larg--;
	}
	if (gl->hash == 2)
	{
		gl->hash = 0;
		ft_putchar('0');
		gl->space++;
		if (!ft_isupper(t))
			ft_putchar('x');
		else
			ft_putchar('X');
		gl->space++;
	}
	unload_hex2(gl, x, str);
}

int		ft_unload_hex(t_print *gl, char *str, unsigned long long int x, char t)
{
	if (!ft_isupper(t))
		str = ft_itoa_base(x, 16);
	else
		str = ft_itoa_base_maj(x, 16);
	gl->space = ft_strlen(str);
	ft_putstr(gl->s);
	if (gl->p < 0)
	{
		if (gl->hash == 2 && gl->c == '0')
		{
			gl->hash = 0;
			ft_putchar('0');
			gl->space++;
			if (!ft_isupper(t))
				ft_putchar('x');
			else
				ft_putchar('X');
			gl->space++;
		}
		unload_hex3(gl, str, x, t);
	}
	if (gl->p >= 0)
		ft_unload_hex2(gl, str, x, t);
	return (gl->space + gl->i + ft_strlen(gl->s));
}

int		ft_nohflag(va_list ap, t_print *gl, char t)
{
	unsigned long long int	x;

	if (t == 'v' || t == 'V')
		x = va_arg(ap, unsigned long long int);
	if (t == 'l' || t == 'L')
		x = va_arg(ap, unsigned long int);
	if (t == 'x' || t == 'X')
		x = va_arg(ap, unsigned int);
	if (t == 's' || t == 'S')
		x = (unsigned short)va_arg(ap, unsigned int);
	if (t == 'c' || t == 'C')
		x = (unsigned char)va_arg(ap, unsigned int);
	if (x == 0)
	{
		ft_putstr(gl->s);
		if (gl->p < 0)
			gl->p = 1;
		while (gl->larg-- > gl->p && gl->i++ < 2147483647)
			ft_putchar(' ');
		while (gl->p-- > 0 && gl->i++ < 2147483647)
			ft_putchar('0');
		return (gl->i + ft_strlen(gl->s));
	}
	return (ft_unload_hex(gl, NULL, x, t));
}

int		ft_hexa_char(char const *fl, va_list ap, t_print *gl)
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
		gl->flag = ft_hexa_flag(fl, ap, gl, 'c');
	ft_strclr(gl->s);
	return (gl->flag);
}

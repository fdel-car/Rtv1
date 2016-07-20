/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 17:20:17 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:42:07 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_noullflag(va_list ap, t_print *gl)
{
	unsigned long long int	u;
	int						space;
	int						temp;

	gl->i = 0;
	u = va_arg(ap, unsigned long long int);
	space = ft_char_uns(u);
	temp = space;
	ft_putstr(gl->s);
	if (gl->p > space)
	{
		while (gl->larg-- > gl->p && gl->i++ < 2147483647)
			ft_putchar(gl->c);
		temp = gl->p;
	}
	else
		while (gl->larg-- > space && gl->i++ < 2147483647)
			ft_putchar(gl->c);
	while (gl->p-- > space)
		ft_putchar('0');
	space = temp;
	ft_putunbr(u);
	return (space + ft_strlen(gl->s) + gl->i);
}

int		ft_flag_unsll(char const *fl, va_list ap, t_print *gl)
{
	while (fl[gl->l - gl->f] == ' ' || fl[gl->l - gl->f] == '+' ||
			fl[gl->l - gl->f] == '#' || fl[gl->l - gl->f] == '-' ||
			fl[gl->l - gl->f] == '0')
	{
		if (fl[gl->l - gl->f] == '-')
			gl->fl_right = 1;
		if (fl[gl->l - gl->f] == '0')
			gl->c = '0';
		gl->f++;
	}
	if (fl[gl->l - gl->f] != '%')
		return (-1);
	if (gl->fl_right == 1)
		return (ft_unload_uns(gl, ap));
	else
		return (ft_noullflag(ap, gl));
}

int		ft_uns_long_long(char const *fl, va_list ap, t_print *gl)
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
		gl->flag = ft_flag_unsll(fl, ap, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_uns_long(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l' || fl[gl->l - gl->f] == 'h')
		gl->f++;
	if (fl[gl->l - gl->f] == 'h' || fl[gl->l - gl->f] == 'j' ||
		fl[gl->l - gl->f] == 'z')
		gl->f++;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_uns_long_long(fl, ap, gl));
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
		gl->flag = ft_flag_unsl(fl, ap, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_unsigned(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	if (fl[gl->l - gl->f] == 'l')
		return (ft_uns_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'z' || fl[gl->l - gl->f] == 'j')
		return (ft_uns_long_long(fl, ap, gl));
	if (fl[gl->l - gl->f] == 'h')
		return (ft_uns_short(fl, ap, gl));
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
		gl->flag = ft_flag_uns(fl, ap, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

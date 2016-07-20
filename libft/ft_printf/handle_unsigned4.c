/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:20:30 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:42:43 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unload_unss(t_print *gl, va_list ap)
{
	unsigned short u;

	ft_putstr(gl->s);
	u = (unsigned short)va_arg(ap, unsigned int);
	gl->space = ft_char_uns(u);
	while (gl->p > gl->space)
	{
		ft_putchar('0');
		gl->space++;
	}
	ft_putunbr(u);
	while (gl->larg-- > gl->space && gl->i++ < 2147483647)
		ft_putchar(gl->c);
	return (gl->space + ft_strlen(gl->s) + gl->i);
}

int		ft_noucflag(va_list ap, t_print *gl)
{
	unsigned char	u;
	int				space;
	int				temp;

	gl->i = 0;
	u = (unsigned char)va_arg(ap, unsigned int);
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

int		ft_flag_unsc(char const *fl, va_list ap, t_print *gl)
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
		return (ft_unload_unsc(gl, ap));
	else
		return (ft_noucflag(ap, gl));
}

int		ft_nousflag(va_list ap, t_print *gl)
{
	unsigned short int	u;
	int					space;
	int					temp;

	gl->i = 0;
	u = (unsigned short)va_arg(ap, unsigned int);
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

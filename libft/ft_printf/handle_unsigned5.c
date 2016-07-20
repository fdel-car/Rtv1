/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 18:39:19 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:42:59 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unload_unsc(t_print *gl, va_list ap)
{
	unsigned char u;

	ft_putstr(gl->s);
	u = (unsigned char)va_arg(ap, unsigned int);
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

int		ft_uns_char(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	while (fl[gl->l - gl->f] == 'h')
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
		gl->flag = ft_flag_unsc(fl, ap, gl);
	ft_strclr(gl->s);
	return (gl->flag);
}

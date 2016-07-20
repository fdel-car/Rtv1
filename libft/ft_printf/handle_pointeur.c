/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointeur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:49:06 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:41:38 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unload_pointeur(t_print *gl, unsigned long long int x, char t)
{
	char *str;

	if (gl->p > 0)
		return (-1);
	if (gl->c == '0')
		return (-1);
	ft_putstr(gl->s);
	if (t == 'p')
		str = ft_itoa_base(x, 16);
	if (t == 'P')
		str = ft_itoa_base_maj(x, 16);
	if (t == 'p')
		ft_putstr("0x");
	if (t == 'P')
		ft_putstr("0X");
	gl->i = gl->i + 2;
	ft_putstr(str);
	free(str);
	if (gl->larg < 0)
		gl->larg = 0;
	while (gl->larg-- > (int)ft_strlen(str) + 2 && gl->i++ < 2147483647)
		ft_putchar(' ');
	return (ft_strlen(gl->s) + ft_strlen(str) + gl->i);
}

int		nopflag(va_list ap, t_print *gl, char t)
{
	unsigned long long int	x;
	char					*str;

	if (gl->p > 0)
		return (-1);
	if (gl->c == '0')
		return (-1);
	ft_putstr(gl->s);
	x = va_arg(ap, unsigned long long int);
	if (t == 'p')
		str = ft_itoa_base(x, 16);
	if (t == 'P')
		str = ft_itoa_base_maj(x, 16);
	if (gl->larg < 0)
		gl->larg = 0;
	while (gl->larg-- > (int)(ft_strlen(str) + 2) && gl->i++ < 2147483647)
		ft_putchar(' ');
	if (t == 'p')
		ft_putstr("0x");
	if (t == 'P')
		ft_putstr("0X");
	gl->i = gl->i + 2;
	ft_putstr(str);
	free(str);
	return (ft_strlen(gl->s) + ft_strlen(str) + gl->i);
}

int		ft_pointeur_flag(char const *fl, va_list ap, t_print *gl, char t)
{
	unsigned long long int	x;

	if (ft_unload_fl_hex(fl, gl) < 0)
		return (-1);
	if (gl->fl_right == 1)
	{
		x = va_arg(ap, unsigned long long int);
		return (ft_unload_pointeur(gl, x, t));
	}
	return (nopflag(ap, gl, t));
}

int		ft_pointeur_maj(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	while (fl[gl->l - gl->f] == 'l' || fl[gl->l - gl->f] == 'j' ||
			fl[gl->l - gl->f] == 'h' || fl[gl->l - gl->f] == 'z')
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
		gl->flag = ft_pointeur_flag(fl, ap, gl, 'P');
	ft_strclr(gl->s);
	return (gl->flag);
}

int		ft_pointeur(char const *fl, va_list ap, t_print *gl)
{
	gl->f = 2;
	gl->i = 0;
	while (fl[gl->l - gl->f] == 'l' || fl[gl->l - gl->f] == 'j' ||
			fl[gl->l - gl->f] == 'h' || fl[gl->l - gl->f] == 'z')
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
		gl->flag = ft_pointeur_flag(fl, ap, gl, 'p');
	ft_strclr(gl->s);
	return (gl->flag);
}

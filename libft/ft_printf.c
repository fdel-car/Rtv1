/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:28:50 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:34:41 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_handle_conv(char c, va_list ap, const char *str, t_print *print)
{
	int				i;
	static t_handle	handle[] = {{&ft_string, 's'}, {&ft_widestring, 'S'},
		{&ft_char, 'c'}, {&ft_widechar, 'C'}, {&ft_unsigned, 'u'},
		{&ft_uns_long, 'U'}, {&ft_int, 'd'}, {&ft_int, 'i'},
		{&ft_int_long, 'D'}, {&ft_octal, 'o'}, {&ft_octal_long, 'O'},
		{&ft_hexa, 'x'}, {&ft_hexa_maj, 'X'}, {&ft_percent, '%'},
		{&ft_pointeur, 'p'}, {&ft_pointeur_maj, 'P'}, {&ft_binaire, 'b'},
		{&ft_binaire_maj, 'B'}, {NULL, -1}};

	i = 0;
	while (handle[i].key != -1)
	{
		if (handle[i].key == c)
			return (handle[i].handle_fonc(str, ap, print));
		i++;
	}
	return (-1);
}

int		ft_specifiers(const char *format)
{
	int i;

	i = 1;
	while (format[i] != 's' && format[i] != 'S' && format[i] != 'p' &&
		format[i] != 'd' && format[i] != 'D' && format[i] != 'i' &&
		format[i] != 'o' && format[i] != 'O' && format[i] != 'u' &&
		format[i] != 'U' && format[i] != 'x' && format[i] != 'X' &&
		format[i] != 'c' && format[i] != 'C' && format[i] != '%' &&
		format[i] != 'P' && format[i] != 'b' && format[i] != 'B')
	{
		if (format[i] == '\0')
			return (-1);
		i++;
	}
	return (i + 1);
}

void	ft_init(t_print *gl)
{
	gl->p = -2;
	gl->inv = 0;
	gl->larg = -2;
	gl->flag = -1;
	gl->s_wide = 1;
	gl->i = 0;
	gl->c = ' ';
	gl->sign = 0;
	gl->neg = 0;
	gl->fl_s = 0;
	gl->hash = 0;
}

int		ft_init_printf(char const *format, va_list ap, int i, t_print *gl)
{
	gl->j = 0;
	ft_strclr(gl->s);
	while (format[i] != '%' && format[i])
		gl->s[gl->j++] = format[i++];
	gl->s[gl->j] = '\0';
	if (format[i] != '\0')
	{
		gl->l = ft_specifiers(format + i);
		if (gl->l == -1)
			return (-1);
		i += gl->l;
		ft_init(gl);
		if ((gl->ret_err = ft_handle_conv(format[i - 1],
			ap, format + i - gl->l, gl)) < 0)
			return (-1);
		gl->ret += gl->ret_err;
		return (ft_init_printf(format, ap, i, gl));
	}
	if (gl->s[0] != 0)
	{
		ft_putstr(gl->s);
		gl->ret += ft_strlen(gl->s);
		ft_strclr(gl->s);
	}
	return (gl->ret);
}

int		ft_printf(char const *format, ...)
{
	va_list ap;
	t_print	gl;
	int		ret;

	gl.ret = 0;
	va_start(ap, format);
	ret = ft_init_printf(format, ap, 0, &gl);
	if (ret < 0)
		return (ret);
	va_end(ap);
	return (ret);
}

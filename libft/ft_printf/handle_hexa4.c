/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 19:59:37 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 16:39:15 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unload_hex(t_print *gl, char *str, unsigned long long int x, char t)
{
	if (gl->hash == 2 && gl->p != 0 && x != 0)
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

void	unload_hex2(t_print *gl, unsigned long long int x, char *str)
{
	while (gl->p > gl->space)
	{
		ft_putchar('0');
		gl->space++;
	}
	if (gl->p == 0 && x == 0)
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

void	unload_hex3(t_print *gl, char *str, unsigned long long x, char t)
{
	while (gl->larg > (gl->space + gl->hash) && gl->i < 2147483647)
	{
		ft_putchar(gl->c);
		gl->larg--;
		gl->i++;
	}
	if (gl->hash == 2 && gl->p != 0 && x != 0)
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
	ft_putstr(str);
	free(str);
}

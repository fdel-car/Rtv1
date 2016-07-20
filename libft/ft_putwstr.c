/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:56:33 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 17:06:47 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stddef.h>

int		ft_check_uni(int c)
{
	if (c < 128)
		return (1);
	if (c < 2048)
		return (2);
	if (c < 65536)
		return (3);
	if (c < 1114112)
		return (4);
	return (-1);
}

int		ft_putwstr(wchar_t const *s, int l)
{
	int i;
	int	o;
	int w;
	int	u;

	w = ft_wstrlen(s);
	o = 0;
	i = 0;
	if (l < 0 || l > w)
		l = w;
	while (i < l && s[i])
	{
		u = ft_check_uni(s[i]);
		if (l < w && l > 0)
		{
			o += u;
			if (o > l)
				return (o - u);
			o -= u;
		}
		o += ft_putchar(s[i]);
		i++;
	}
	return (o);
}

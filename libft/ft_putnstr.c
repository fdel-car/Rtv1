/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:59:42 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/03 15:47:23 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <unistd.h>

int		ft_putnstr(char const *s, size_t n)
{
	size_t temp;

	temp = ft_strlen(s);
	if (n > temp)
		n = temp;
	write(1, s, n);
	return (n);
}

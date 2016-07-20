/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:09:21 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/27 20:27:06 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= ('a' + base - 10)));
}

int		ft_atoi_base(char *str, int base)
{
	int	value;
	int	sign;

	value = 0;
	if (base <= 1 || base > 36)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'a' >= 0)
			value = value * base + (*str - 'a' + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * sign);
}

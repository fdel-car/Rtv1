/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:31:59 by fdel-car          #+#    #+#             */
/*   Updated: 2015/11/26 16:51:55 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	if (n == 0)
		return (s);
	temp = (unsigned char*)s;
	while (n >= 1)
	{
		*temp = (unsigned char)c;
		n--;
		temp++;
	}
	return (s);
}

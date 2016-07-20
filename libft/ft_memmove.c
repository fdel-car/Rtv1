/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:11:30 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/16 22:41:29 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;

	str_dest = (unsigned char*)dest;
	str_src = (unsigned char*)src;
	if (str_dest > str_src)
	{
		while (n--)
			str_dest[n] = str_src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

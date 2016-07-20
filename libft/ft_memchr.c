/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:35:39 by fdel-car          #+#    #+#             */
/*   Updated: 2015/11/30 15:24:54 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (str[i] == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:49:00 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/03 16:52:12 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char*)dest;
	str2 = (char*)src;
	i = 0;
	while (i < n)
	{
		i++;
		*str1 = *str2;
		if (*str1 == c)
			return (dest + i);
		str1++;
		str2++;
	}
	return (NULL);
}

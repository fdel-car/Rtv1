/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:51:04 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/07 21:18:39 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n < ft_strlen(s2) && s1[i])
		return (NULL);
	if (n == 0)
		return (NULL);
	if (!s2[i])
		return ((char*)s1);
	while (s1[i] && i <= (n - ft_strlen(s2)))
	{
		if (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}

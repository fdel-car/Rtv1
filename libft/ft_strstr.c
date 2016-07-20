/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:51:04 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/03 20:28:58 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] && i <= (ft_strlen(haystack) - ft_strlen(needle)))
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}

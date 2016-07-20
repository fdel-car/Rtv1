/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:36:28 by fdel-car          #+#    #+#             */
/*   Updated: 2016/02/23 22:43:32 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return ((char*)s2);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i++];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i++];
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

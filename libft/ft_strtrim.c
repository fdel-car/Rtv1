/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:25:04 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/08 19:52:44 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(char const *s, int n)
{
	int i;
	int m;

	m = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
			i++;
		while (s[i] != '\n' && s[i] != '\t' && s[i] != ' ')
		{
			i++;
			n++;
			m++;
		}
		while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		{
			i++;
			m++;
		}
		if (s[i] != '\0')
			n = m;
	}
	return (n);
}

char		*ft_strtrim(char const *s)
{
	int		size;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	size = ft_count(s, 0);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	while (j < size)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

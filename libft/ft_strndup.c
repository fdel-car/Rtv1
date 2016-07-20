/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:17:00 by fdel-car          #+#    #+#             */
/*   Updated: 2016/02/23 21:54:04 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * n + 1);
	if (!temp)
		return (NULL);
	while (s[i] && n > 0)
	{
		temp[i] = s[i];
		i++;
		n--;
	}
	temp[i] = '\0';
	return (temp);
}

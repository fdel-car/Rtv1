/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:07:09 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/03 16:06:50 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *place;

	place = NULL;
	while (*s)
	{
		if (*s == c)
			place = (char*)s;
		s++;
	}
	if (*s == c)
		place = (char*)s;
	return (place);
}

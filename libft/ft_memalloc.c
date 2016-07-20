/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:10:26 by fdel-car          #+#    #+#             */
/*   Updated: 2015/11/30 16:00:54 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = (void *)malloc(sizeof(void) * size);
	if (area == NULL)
		return (NULL);
	ft_memset(area, 0, size);
	return (area);
}

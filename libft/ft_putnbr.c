/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:12:51 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/30 17:04:56 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_signfl(t_print *gl, long long int in)
{
	if (gl->sign == 0 || in < 0)
		return (0);
	else
		return (1);
}

int		ft_char_int(long long int in)
{
	int				i;
	long long int	temp;

	i = 0;
	if (in == 0)
		return (1);
	temp = in;
	if (temp < 0)
	{
		temp = -temp;
	}
	while ((temp) != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

int		ft_char_uns(unsigned long long int u)
{
	int						i;
	unsigned long long int	temp;

	i = 0;
	if (u == 0)
		return (1);
	temp = u;
	while ((temp) != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

void	ft_putunbr(unsigned long long int n)
{
	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
		return ;
	}
	else
	{
		ft_putchar(n + 48);
	}
}

void	ft_putnbr(long long int n)
{
	unsigned long long	tmp;
	long long			tmp2;

	tmp = 9223372036854775807;
	tmp2 = -9223372036854775807;
	tmp++;
	tmp2--;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == tmp2)
			return (ft_putunbr(tmp));
		else
			n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		return ;
	}
	else
	{
		ft_putchar(n + 48);
	}
}

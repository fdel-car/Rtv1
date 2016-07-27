/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:56:16 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/26 15:56:18 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_plan(t_obj **first_ob, char *line)
{
	t_obj	*new;
	char	**tab;
	int		i;

	i = 0;
	new = (t_obj *)malloc(sizeof(t_obj));
	new->type = 2;
	tab = ft_strsplit(line, ' ');
	free(line);
	new->norm = create_vect(ft_atof(tab[2]), ft_atof(tab[3]), ft_atof(tab[4]));
	new->pos = create_vect(ft_atof(tab[6]), ft_atof(tab[7]), ft_atof(tab[8]));
	new->color = create_color(ft_atoi(tab[10]),	ft_atoi(tab[11]), ft_atoi(tab[12]));
	new->cons = -dot_product(new->pos, new->norm);
	new->next = NULL;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	add_node(first_ob, new);
}

// void	add_cylinder(t_obj **first_ob, char *line)
// {
// 	t_obj	*new;
// 	char	**tab;
// 	int		i;
//
// 	i = 0;
// 	new = (t_obj *)malloc(sizeof(t_obj));
// 	new->type = 3;
// 	tab = ft_strsplit(line, ' ');
// 	free(line);
// 	new->color = create_color(ft_atoi(tab[2]), ft_atoi(tab[3]),
// 	ft_atoi(tab[4]));
// 	new->next = NULL;
// 	while (tab[i])
// 		free(tab[i++]);
// 	free(tab);
// 	add_node(first_ob, new);
// }

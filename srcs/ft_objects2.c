/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:10:47 by fdel-car          #+#    #+#             */
/*   Updated: 2018/09/19 15:48:59 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		protection(char **tab, t_obj *new, int n)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	if (i <= n)
	{
		free(new);
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
		return (1);
	}
	return (0);
}

void	add_cylinder(t_obj **first_ob, char *line)
{
	t_obj	*new;
	char	**tab;
	int		i;

	i = 0;
	new = (t_obj *)malloc(sizeof(t_obj));
	new->type = 3;
	tab = ft_strsplit(line, ' ');
	if (protection(tab, new, 14))
		return ;
	new->rayon = atof(tab[2]);
	new->pos = create_vect(atof(tab[4]), atof(tab[5]), atof(tab[6]));
	new->dir = normalize(create_vect(atof(tab[8]), atof(tab[9]),
	atof(tab[10])));
	new->color = create_color(atoi(tab[12]), atoi(tab[13]),
	atoi(tab[14]));
	new->next = NULL;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	add_node(first_ob, new);
}

void	add_cone(t_obj **first_ob, char *line)
{
	t_obj	*new;
	char	**tab;
	int		i;

	i = 0;
	new = (t_obj *)malloc(sizeof(t_obj));
	new->type = 4;
	tab = ft_strsplit(line, ' ');
	if (protection(tab, new, 14))
		return ;
	new->alpha = atof(tab[2]) * M_PI / 180;
	if (new->alpha > 1.5707)
		new->alpha = 1.5707;
	new->pos = create_vect(atof(tab[4]), atof(tab[5]), atof(tab[6]));
	new->dir = normalize(create_vect(atof(tab[8]), atof(tab[9]),
	atof(tab[10])));
	new->color = create_color(atoi(tab[12]), atoi(tab[13]),
	atoi(tab[14]));
	new->next = NULL;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	add_node(first_ob, new);
}

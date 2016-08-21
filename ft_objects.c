/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:45:52 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/21 20:30:47 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_node(t_obj **first_ob, t_obj *new)
{
	t_obj	*temp;

	if (!(*first_ob))
	{
		*first_ob = new;
		return ;
	}
	temp = *first_ob;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	add_light(t_obj **first_ob, char *line)
{
	t_obj	*new;
	char	**tab;
	int		i;

	i = 0;
	new = (t_obj *)malloc(sizeof(t_obj));
	new->type = 0;
	tab = ft_strsplit(line, ' ');
	free(line);
	if (protection(tab, new, 8))
		return ;
	new->pos = create_vect(ft_atof(tab[2]), ft_atof(tab[3]), ft_atof(tab[4]));
	new->color = create_color(ft_atoi(tab[6]), ft_atoi(tab[7]),
	ft_atoi(tab[8]));
	new->next = NULL;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	add_node(first_ob, new);
}

void	add_cercle(t_obj **first_ob, char *line)
{
	t_obj	*new;
	char	**tab;
	int		i;

	i = 0;
	new = (t_obj *)malloc(sizeof(t_obj));
	new->type = 1;
	tab = ft_strsplit(line, ' ');
	free(line);
	if (protection(tab, new, 10))
		return ;
	new->rayon = ft_atof(tab[2]);
	new->pos = create_vect(ft_atof(tab[4]), ft_atof(tab[5]), ft_atof(tab[6]));
	new->color = create_color(ft_atoi(tab[8]), ft_atoi(tab[9]),
	ft_atoi(tab[10]));
	new->next = NULL;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	add_node(first_ob, new);
}

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
	if (protection(tab, new, 12))
		return ;
	new->norm = create_vect(ft_atof(tab[2]), ft_atof(tab[3]), ft_atof(tab[4]));
	new->pos = create_vect(ft_atof(tab[6]), ft_atof(tab[7]), ft_atof(tab[8]));
	new->color = create_color(ft_atoi(tab[10]), ft_atoi(tab[11]),
	ft_atoi(tab[12]));
	new->cons = -dotp_n(new->pos, new->norm);
	new->next = NULL;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	add_node(first_ob, new);
}

t_obj	*ft_objects(char *scene)
{
	int		fd;
	t_obj	*first_ob;
	char	*line;

	first_ob = NULL;
	fd = open(scene, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '0')
			add_light(&first_ob, line);
		if (line[0] == '1')
			add_cercle(&first_ob, line);
		if (line[0] == '2')
			add_plan(&first_ob, line);
		if (line[0] == '3')
			add_cylinder(&first_ob, line);
		if (line[0] == '4')
			add_cone(&first_ob, line);
	}
	if (line)
		free(line);
	close(fd);
	return (first_ob);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:45:52 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/20 14:45:54 by fdel-car         ###   ########.fr       */
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

void    add_cercle(t_obj **first_ob, char *line)
{
    t_obj   *new;
    char    **tab;
	int		i;

	i = 0;
    new = (t_obj *)malloc(sizeof(t_obj));
    new->type = 1;
    tab = ft_strsplit(line, ' ');
	free(line);
    new->rayon = ft_atof(tab[2]);
    new->pos = create_vect(ft_atof(tab[4]), ft_atof(tab[5]), ft_atof(tab[6]));
    new->color = ft_atoi(tab[7]);
    new->next = NULL;
	while (tab[i])
		free(tab[i++]);
	free(tab);
    add_node(first_ob, new);
}

t_obj   *ft_objects(char *scene)
{
    int     fd;
    t_obj   *first_ob;
    char    *line;

	first_ob = NULL;
    fd = open(scene, O_RDONLY);
    if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
    {
        if (line[0] == '1')
            add_cercle(&first_ob, line);
    }
	free(line);
    close(fd);
    return (first_ob);
}

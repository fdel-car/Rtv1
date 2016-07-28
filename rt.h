/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 11:41:02 by fdel-car          #+#    #+#             */
/*   Updated: 2016/07/11 18:07:51 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define EPSILON 0.001

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"

// ATTENTION
# include <stdio.h>
// ATTENTION

typedef struct	s_graph
{
	int			s_x;
	int			s_y;
	void		*mlx;
	void		*win;
	void		*img;
	int			endian;
	int			bpp;
	int			sizeline;
	char		*disp;
	int			x;
	int			y;
}				t_graph;

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_rayt
{
	double		view_d;
	double		view_h;
	double		view_w;
	t_vect		c_pos;
	t_vect		look_at;
	t_vect		vec_up;
	t_vect		vec_right;
	t_vect		vec_dir;
	t_vect		up_left;
	double		x_ind;
	double		y_ind;
	t_vect		light;
	double		a;
	double		t1;
	double		t2;
	double		solut;
	double		delta;
	double		cosinus;
}				t_rayt;

typedef struct	s_obj
{
	t_vect		pos;
	int			type;
	void		*next;
	double		rayon;
	t_color		color;
	t_vect		norm;
	double		cons;
}				t_obj;

typedef struct	s_node
{
	t_vect		hit_point;
	double		dist;
	t_obj		*obj;
}				t_node;

typedef struct	s_glob
{
	t_rayt		*rt;
	t_graph		*gr;
	t_obj		*obj;
}				t_glob;

int				ft_rt(t_glob *gl);
void			raytracing(t_rayt *rt, t_graph *gr, t_obj *obj);
t_vect			multiple(t_vect u, t_vect v);
t_vect			multiple_value(t_vect u, double value);
t_vect  		subtract(t_vect u, t_vect v);
t_vect			add(t_vect u, t_vect v);
t_vect			normalize(t_vect u);
void			ft_setpixel(t_graph *gr, int x, int y, t_color color);
int				ft_color(t_rayt *rt);
double			dot_product(t_vect u, t_vect v);
t_obj			*ft_objects(char *scene);
t_vect			create_vect(double x, double y, double z);
t_color			ft_light(t_node *node, t_rayt *rt, t_obj *obj);
t_color			add_color(t_color u, t_color v);
t_color			subtract_color(t_color u, t_color v);
t_color			multiple_color(t_color color, double value);
t_color			create_color(int r, int g, int b);
t_node			*hit_cercle(t_rayt *rt, t_obj *obj, t_node *node, t_vect from);
t_node			*hit_plan(t_rayt *rt, t_obj *obj, t_node *node, t_vect from);
t_node			*hit_cylinder(t_rayt *rt, t_obj *obj, t_node *node, t_vect from);
void			add_plan(t_obj **first_ob, char *line);
void			add_cylinder(t_obj **first_ob, char *line);
void			add_node(t_obj **first_ob, t_obj *new);
void			update_node(t_obj *obj, t_vect hit, double dist, t_node *node);
int				ft_key(int keycode, t_glob *gl);
int				ft_close();

#endif

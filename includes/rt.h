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
# define NUM_THREAD 8
# define EPSILON 0.001
# define SQ(x) ((x) * (x))

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef	struct		s_vect
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef	struct		s_obj
{
	int				type;
	float			rayon;
	t_vect			pos;
	t_vect			norm;
	t_vect			dir;
	t_color			color;
	float			cons;
	float			alpha;
	void			*next;
}					t_obj;

typedef struct		s_rt
{
	t_vect			point;
	t_vect			vec_dir;
	int				y_max;
	int				x;
	int				y;
}					t_rt;

typedef struct		s_info
{
	t_vect			fr;
	t_vect			dir;
	t_vect			tmp;
	t_obj			*obj;
	float			a;
	float			a_cone;
	float			b;
	float			c;
	float			delta;
	float			t1;
	float			t2;
	float			solut;
}					t_info;

typedef struct		s_data
{
	t_obj			*obj;
	void			*mlx;
	void			*win;
	void			*img;
	int				s_x;
	int				s_y;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*disp;
	pthread_mutex_t	mutex_img;
	pthread_cond_t	cond_img;
	int				id;
	float			x_ind;
	float			y_ind;
	float			init;
	float			view_d;
	float			view_h;
	float			view_w;
	t_vect			a_x;
	t_vect			init_dir;
	t_vect			vec_dir;
	t_vect			vec_up;
	t_vect			vec_right;
	t_vect			up_left;
	t_vect			cam_p;
	t_vect			look;
}					t_data;

typedef struct		s_ray
{
	t_color			clr;
	t_vect			hit_point;
	t_vect			light;
	t_vect			refl;
	t_vect			norm;
	float			dist;
	float			dist_p;
	float			cosinus;
	t_obj			*obj;
	t_obj			*lst_obj;
	int				sh;
	int				lght;
}					t_ray;

void				ft_setpixel(t_data *data, int x, int y, t_color color);
void				add_cylinder(t_obj **first_ob, char *line);
void				add_cone(t_obj **first_ob, char *line);
void				add_node(t_obj **first_ob, t_obj *new);
void				loop(t_data *dt, t_rt *rt, t_ray *ray);
void				init_data(t_data *data);
void				ray_light(t_ray *ray, t_obj *obj);
t_ray				*hit_cercle(t_ray *ray, t_info *inf);
t_ray				*hit_plan(t_ray *ray, t_info *inf);
t_ray				*hit_cylinder(t_ray *ray, t_info *inf);
t_ray				*hit_cone(t_ray *ray, t_info *inf);
t_ray				*hit_obj(t_data *data, t_vect fr, t_vect dir, t_ray *ray);
t_color				create_color(int r, int g, int b);
t_color				multiple_color(t_color color, float value);
t_color				add_color(t_color u, t_color v);
t_color				subtract_color(t_color u, t_color v);
t_color				ft_light(t_ray *ray);
t_vect				norm_cone(t_ray *ray);
t_vect				norm_cylinder(t_ray *ray);
t_vect				create_vect(float x, float y, float z);
t_vect				multiple(t_vect u, t_vect v);
t_vect				multiple_value(t_vect u, float value);
t_vect				subtract(t_vect u, t_vect v);
t_vect				add(t_vect u, t_vect v);
t_vect				normalize(t_vect u);
t_vect				create_vect(float x, float y, float z);
t_vect				rot_x(float theta, t_vect u);
t_vect				rot_y(float theta, t_vect u);
t_vect				rot_z(float theta, t_vect u);
t_vect				rot_any(t_vect u, t_vect a, float theta);
t_obj				*ft_objects(char *scene, int fd);
float				dotp_n(t_vect u, t_vect v);
float				dist_p(t_vect u, t_vect v);
int					loop_shadow(t_info *inf, t_ray *sh_ray, t_obj *obj,
					float dist);
int					find_shadow(t_obj *obj, t_vect dir, t_vect fr, float dist);
int					key_handle(int keycode, t_data *data);
int					protection(char **tab, t_obj *new, int n);
int					build_img(t_data data);
int					ft_close(t_data *data);

#endif

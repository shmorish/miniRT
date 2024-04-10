/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:08:19 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/10 23:56:40 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_object_type			t_object_type;

typedef struct s_rgb				t_rgb;
typedef struct s_float_rgb			t_float_rgb;
typedef struct s_vector				t_vector;
typedef struct s_ambient_lightning	t_ambient_lightning;
typedef struct s_camera				t_camera;
typedef struct s_light				t_light;
typedef struct s_sphere				t_sphere;
typedef struct s_plane				t_plane;
typedef struct s_cylinder			t_cylinder;
typedef struct s_object				t_object;
typedef struct s_is_set				t_is_set;
typedef struct s_mlx				t_mlx;
typedef struct s_data				t_data;
typedef struct s_quadratic_equation	t_quadratic_equation;

enum e_object_type
{
	HEAD_TYPE,
	PLANE_TYPE,
	SPHERE_TYPE,
	CYLINDER_TYPE,
};

# define WINDOW_WIDTH	800.0
# define WINDOW_HEIGHT	600.0

struct s_rgb
{
	int	red;
	int	green;
	int	blue;
};

struct s_float_rgb
{
	int	red;
	int	green;
	int	blue;
};

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

struct s_ambient_lightning
{
	double	ratio;
	int		color;
};

struct s_camera
{
	t_vector	coordinate;
	t_vector	direction;
	double		fov;
};

struct s_light
{
	t_vector	position;
	double		ratio;
	int			color;
};

struct s_sphere
{
	t_vector	coordinate;
	double		diameter;
	int			color;
};

struct s_plane
{
	t_vector	coordinate;
	t_vector	direction;
	int			color;
};

// なんとかする
struct s_quadratic_equation
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;
	double	t1;
	double	t2;
};

struct s_cylinder
{
	t_vector				coordinate;
	t_vector				direction;
	double					diameter;
	double					height;
	int						color;
	t_quadratic_equation	t;
};

struct s_object
{
	t_object_type	type;
	void			*object_data;
	t_object		*next;
};

struct s_is_set
{
	bool	ambient_lightning;
	bool	camera;
	bool	light;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct s_data
{
	t_ambient_lightning	ambient_lightning;
	t_camera			camera;
	t_light				light;
	t_object			*object;
	t_is_set			is_set;
	t_mlx				*mlx;
};

#endif

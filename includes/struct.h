/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:08:19 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 07:34:35 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_rgb				t_rgb;
typedef struct s_vector				t_vector;
typedef struct s_ambient_lightning	t_ambient_lightning;
typedef struct s_camera				t_camera;
typedef struct s_light				t_light;
typedef struct s_is_set				t_is_set;
typedef struct s_data				t_data;

struct s_rgb
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
	t_vector	origin;
	t_vector	direction;
	double		fov;
};

struct s_light
{
	t_vector	position;
	double		ratio;
	int			color;
};

struct s_is_set
{
	bool	ambient_lightning;
	bool	camera;
	bool	light;
};

struct s_data
{
	t_ambient_lightning	ambient_lightning;
	t_camera			camera;
	t_light				light;
	t_is_set			is_set;
};

#endif

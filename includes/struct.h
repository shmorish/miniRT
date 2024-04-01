/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:08:19 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 00:55:58 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_rgb				t_rgb;
typedef struct s_vector				t_vector;
typedef struct s_data				t_data;
typedef struct s_ambient_lightning	t_ambient_lightning;
typedef struct s_camera				t_camera;

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

// 明度？輝度？変わるはずだからrgb別々に保持しておきます
struct s_ambient_lightning
{
	double	ratio;
	t_rgb	color;
};

struct s_camera
{
	t_vector	origin;
	t_vector	direction;
	double		fov;
};

struct s_data
{
	t_ambient_lightning	ambient_lightning;
	t_camera			camera;
};

#endif

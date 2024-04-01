/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:08:19 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 23:19:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_rgb				t_rgb;
typedef struct s_data				t_data;
typedef struct s_ambient_lightning	t_ambient_lightning;

struct s_rgb
{
	int	red;
	int	green;
	int	blue;
};

// 明度？輝度？変わるはずだからrgb別々に保持しておきます
struct s_ambient_lightning
{
	double	ratio;
	t_rgb	color;
};

struct s_data
{
	int	test;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 02:29:27 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/05 02:48:34 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "struct.h"

// additon.c
t_vector	addition(t_vector a, t_vector b);

// cross_product.c
t_vector	cross_product(t_vector a, t_vector b);

// distance.c
double		distance(t_vector a, t_vector b);

// division.c
t_vector	division(t_vector a, t_vector b);

// dot_product.c
double		dot_product(t_vector a, t_vector b);

// magnitude_squared.c
double		magnitude_squared(t_vector v);

// magnitude.c
double		magnitude(t_vector v);

// normalize.c
t_vector	normalize(t_vector v);

// multiplication.c
t_vector	multiplication(t_vector a, t_vector b);

// normalize.c
t_vector	normalize(t_vector v);

// scale.c
t_vector	scale(t_vector v, double scale);
t_rgb       scale_rgb(t_rgb v, double scale);

// subtraction.c
t_vector	subtraction(t_vector a, t_vector b);

#endif

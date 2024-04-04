/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 02:29:27 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/05 02:36:52 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "struct.h"

// additon.c
t_vector	addition(t_vector a, t_vector b);

// cross_product.c
t_vector	cross_product(t_vector a, t_vector b);

// division.c
t_vector	division(t_vector a, t_vector b);

// dot_product.c
double		dot_product(t_vector a, t_vector b);

// multiplication.c
t_vector	multiplication(t_vector a, t_vector b);

// subtraction.c
t_vector	subtraction(t_vector a, t_vector b);

#endif

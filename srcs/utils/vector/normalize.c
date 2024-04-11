/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:48:06 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/10 23:48:06 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	normalize(t_vector v)
{
	const double	mag = magnitude(v);
	const t_vector	mag_v = {mag, mag, mag};

	return (division(v, mag_v));
}

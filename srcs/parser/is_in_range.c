/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:17:39 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 09:03:56 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_in_range_double(double value, double min, double max)
{
	return (min <= value && value <= max);
}

// bool	is_in_range_int(int value, int min, int max)
// {
// 	return (min <= value && value <= max);
// }

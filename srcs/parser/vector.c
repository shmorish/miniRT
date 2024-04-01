/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:59:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 05:13:22 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	validate_and_parse_vector(char *str)
{
	t_vector	vector;
	char		**split;

	split = ft_split(str, ',');
	if (split == NULL)
		print_error_and_exit(ERR_MALLOC);
	is_split_count(split, 3, "Invalid format of vector");
	vector.x = validate_and_parse_double(split[0]);
	vector.y = validate_and_parse_double(split[1]);
	vector.z = validate_and_parse_double(split[2]);
	free_split(split);
	return (vector);
}

t_vector	validate_and_parse_vector_range(char *str, double min, double max)
{
	t_vector	vector;

	vector = validate_and_parse_vector(str);
	if (!is_in_range_double(vector.x, min, max) ||
		!is_in_range_double(vector.y, min, max) ||
		!is_in_range_double(vector.z, min, max))
		print_error_and_exit("Invalid range of vector");
	return (vector);
}

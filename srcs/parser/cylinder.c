/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 07:27:26 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:27:27 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cylinder	*cylinder(char *line)
{
	t_cylinder		*cylinder;
	char			**split;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		print_error_and_exit("malloc failed");
	split = split_string_by_whitespace(line);
	is_split_count(split, 6, ERR_CYLINDER_ARGC);
	if (ft_strcmp(split[0], CYLINDER) != 0)
		print_error_and_exit(ERR_UNKNOWN);
	cylinder->coordinate = validate_and_parse_vector(split[1]);
	cylinder->direction = validate_and_parse_vector_range(split[2], -1, 1);
	cylinder->diameter = validate_and_parse_double(split[3]);
	cylinder->height = validate_and_parse_double(split[4]);
	cylinder->color = validate_and_parse_rgb(split[5]);
	free_split(split);
	return (cylinder);
}

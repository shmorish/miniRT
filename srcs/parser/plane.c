/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 07:27:31 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:21:13 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	*plane(char *line)
{
	t_plane		*plane;
	char		**split;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		print_error_and_exit("malloc failed");
	split = split_string_by_whitespace(line);
	is_split_count(split, 4, ERR_PLANE_ARGC);
	if (ft_strcmp(split[0], PLANE) != 0)
		print_error_and_exit(ERR_UNKNOWN);
	plane->coordinate = validate_and_parse_vector(split[1]);
	plane->direction = validate_and_parse_vector_range(split[2], -1, 1);
	plane->color = validate_and_parse_rgb(split[3]);
	free_split(split);
	return (plane);
}

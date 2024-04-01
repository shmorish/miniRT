/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:31:15 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:14:05 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_camera	camera(t_is_set *is_set, char *line)
{
	t_camera		camera;
	char			**split;

	if (is_set->camera == true)
		print_error_and_exit(ERR_CAMERA_DUPLICATE);
	split = split_string_by_whitespace(line);
	is_split_count(split, 4, ERR_CAMERA_ARGC);
	if (ft_strcmp(split[0], CAMERA) != 0)
		print_error_and_exit(ERR_UNKNOWN);
	camera.coordinate = validate_and_parse_vector(split[1]);
	camera.direction = validate_and_parse_vector_range(split[2], -1, 1);
	camera.fov = validate_and_parse_double_range(split[3], 0, 180);
	free_split(split);
	is_set->camera = true;
	return (camera);
}

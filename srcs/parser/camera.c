/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:31:15 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:18:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_camera			camera(t_is_set *is_set, char *line)
{
	t_camera		camera;
	char			**split;
	size_t			cnt;

	if (is_set->camera == true)
		print_error_and_exit(ERR_CAMERA_DUPLICATE);
	split = split_string_by_whitespace(line);
	cnt = count_split(split);
	if (cnt != 4)
		print_error_and_exit(ERR_CAMERA_ARGC);
	camera.origin = parse_vector(split[1]);
	camera.direction = parse_vector(split[2]);
	camera.fov = ft_atof(split[3]);
	free_split(split);
	is_set->camera = true;
	return (camera);
}

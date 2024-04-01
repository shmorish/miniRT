/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:31:15 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:13:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector title(char **split)
{
	t_vector vector;

	vector.x = ft_atof(split[0]);
	vector.y = ft_atof(split[1]);
	vector.z = ft_atof(split[2]);
	return (vector);

}

t_vector	parse_vector(char *str)
{
	t_vector	vector;
	char		**split;
	size_t		cnt;

	split = ft_split(str, ',');
	if (split == NULL)
		print_error_and_exit(ERR_MALLOC);
	cnt = count_split(split);
	if (cnt != 3)
		print_error_and_exit(ERR_CAMERA_ARGC);
	vector = title(split);
	free_split(split);
	return (vector);
}

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

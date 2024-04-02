/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:35:17 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:39:21 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	parse_line(t_data *data, char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, AMBIENT_LIGHTNING, 1) == 0)
		data->ambient_lightning = ambient_lightning(&data->is_set, line);
	else if (ft_strncmp(line, CAMERA, 1) == 0)
		data->camera = camera(&data->is_set, line);
	else if (ft_strncmp(line, LIGHT, 1) == 0)
		data->light = light(&data->is_set, line);
	else if (ft_strncmp(line, SPHERE, 2) == 0)
		object_list_addback(data->object, object_list_new(SPHERE_TYPE, line));
	else if (ft_strncmp(line, PLANE, 2) == 0)
		object_list_addback(data->object, object_list_new(PLANE_TYPE, line));
	else if (ft_strncmp(line, CYLINDER, 2) == 0)
		object_list_addback(data->object, object_list_new(CYLINDER_TYPE, line));
	else
		print_error_and_exit(ERR_UNKNOWN);
}

void	input_file(t_data *data, char *argv)
{
	char	*line;
	int		fd;

	fd = open_file_and_return_descriptor(argv);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		parse_line(data, line);
		free(line);
	}
}

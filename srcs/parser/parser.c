/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:28:54 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/03 03:34:27 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	is_set_init(t_is_set *is_set)
{
	is_set->ambient_lightning = false;
	is_set->camera = false;
	is_set->light = false;
}

static void	check_is_set(t_is_set is_set)
{
	if (is_set.ambient_lightning == false
		|| is_set.camera == false
		|| is_set.light == false)
		print_error_and_exit("ambient lightning, camera, light, must be set");
}

void	parser(t_data *data, int argc, char **argv)
{
	is_set_init(&data->is_set);
	data->object = object_list_head();
	check_argument(argc, argv);
	check_and_exit_if_directory(argv[1]);
	input_file(data, argv[1]);
	check_is_set(data->is_set);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:28:54 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:38:26 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	is_set_init(t_is_set *is_set)
{
	is_set->ambient_lightning = false;
	is_set->camera = false;
	is_set->light = false;
}

void	parser(t_data *data, int argc, char **argv)
{
	is_set_init(&data->is_set);
	data->object = object_list_head();
	check_argument(argc, argv);
	check_and_exit_if_directory(argv[1]);
	input_file(data, argv[1]);
}

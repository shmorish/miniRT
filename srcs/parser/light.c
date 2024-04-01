/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 07:27:20 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 07:38:05 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light	light(t_is_set *is_set, char *line)
{
	t_light			light;
	char			**split;

	if (is_set->light == true)
		print_error_and_exit(ERR_LIGHT_DUPLICATE);
	split = split_string_by_whitespace(line);
	is_split_count(split, 4, ERR_LIGHT_ARGC);
	if (ft_strcmp(split[0], LIGHT) != 0)
		print_error_and_exit(ERR_UNKNOWN);
	light.position = validate_and_parse_vector(split[1]);
	light.ratio = validate_and_parse_double_range(split[2], 0, 1);
	light.color = validate_and_parse_rgb(split[3]);
	is_set->light = true;
	free_split(split);
	return (light);
}

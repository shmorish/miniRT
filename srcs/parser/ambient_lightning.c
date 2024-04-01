/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:38:38 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:47:43 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ambient_lightning	ambient_lightning(t_is_set *is_set, char *line)
{
	t_ambient_lightning	ambient_lightning;
	char				**split;

	if (is_set->ambient_lightning == true)
		print_error_and_exit(ERR_AL_DUPLICATE);
	split = split_string_by_whitespace(line);
	is_split_count(split, 3, ERR_AL_ARGC);
	if (ft_strcmp(split[0], AMBIENT_LIGHTNING) != 0)
		print_error_and_exit(ERR_UNKNOWN);
	ambient_lightning.ratio = validate_and_parse_double(split[1]);
	if (!is_in_range_double(ambient_lightning.ratio, 0, 1))
		print_error_and_exit(ERR_AL_RATIO);
	ambient_lightning.color = validate_and_parse_rgb(split[2]);
	free_split(split);
	is_set->ambient_lightning = true;
	return (ambient_lightning);
}

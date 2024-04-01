/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:38:38 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 01:08:59 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	validate_and_parse_ambient_light_ratio(char *str)
{
	double	ratio;

	ratio = ft_atof(str);
	if (ratio < 0 || 1 < ratio)
		print_error_and_exit(ERR_AL_RATIO);
	return (ratio);
}

t_ambient_lightning	ambient_lightning(char *line)
{
	t_ambient_lightning	ambient_lightning;
	char				**split;
	size_t				cnt;

	split = split_string_by_whitespace(line);
	cnt = count_split(split);
	if (cnt != 3)
		print_error_and_exit(ERR_AMBIENT_LIGHTNING);
	ambient_lightning.ratio = validate_and_parse_ambient_light_ratio(split[1]);
	ambient_lightning.color = validate_and_parse_rgb(split[2]);
	free_split(split);
	return (ambient_lightning);
}
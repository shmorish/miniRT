/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:33:16 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 00:50:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	validate_and_exit_if_invalid_rgb_values(char *rgb)
{
	if (ft_atoi(rgb) < 0 || 255 < ft_atoi(rgb))
		print_error_and_exit(ERR_RGB_RANGE);
}

t_rgb	parse_rgb_values(char **split)
{
	t_rgb	rgb;

	rgb.red = ft_atoi(split[0]);
	rgb.green = ft_atoi(split[1]);
	rgb.blue = ft_atoi(split[2]);
	return rgb;
}

t_rgb	validate_and_parse_rgb(char *str)
{
	t_rgb	rgb;
	char	**split;
	size_t	cnt = -1;

	split = ft_split(str, ',');
	if (split == NULL)
		print_error_and_exit(ERR_MALLOC);
	while (split[++cnt])
		validate_and_exit_if_invalid_rgb_values(split[cnt]);
	if (cnt != 3)
		print_error_and_exit(ERR_RGB_ARGS);
	rgb = parse_rgb_values(split);
	free_split(split);
	return rgb;
}

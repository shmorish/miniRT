/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:33:16 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:06:35 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	validate_and_exit_if_invalid_rgb_values(char *rgb)
{
	if (ft_atoi(rgb) < 0 || 255 < ft_atoi(rgb))
		print_error_and_exit(ERR_RGB_RANGE);
}

static int	parse_rgb_values(char **split)
{
	char	*red;
	char	*green;
	char	*blue;

	red = split[0];
	green = split[1];
	blue = split[2];
	return (ft_atoi(red) << 16 | ft_atoi(green) << 8 | ft_atoi(blue));
}

int	validate_and_parse_rgb(char *str)
{
	int		rgb;
	char	**split;
	size_t	cnt;

	split = ft_split(str, ',');
	if (split == NULL)
		print_error_and_exit(ERR_MALLOC);
	cnt = -1;
	while (split[++cnt])
		validate_and_exit_if_invalid_rgb_values(split[cnt]);
	if (cnt != 3)
		print_error_and_exit(ERR_RGB_ARGS);
	rgb = parse_rgb_values(split);
	free_split(split);
	return (rgb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 07:27:36 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:14:53 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	*sphere(char *line)
{
	t_sphere		*sphere;
	char			**split;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		print_error_and_exit("malloc failed");
	split = split_string_by_whitespace(line);
	is_split_count(split, 4, ERR_SPHERE_ARGC);
	if (ft_strcmp(split[0], SPHERE) != 0)
		print_error_and_exit(ERR_UNKNOWN);
	sphere->coordinate = validate_and_parse_vector(split[1]);
	sphere->diameter = validate_and_parse_double(split[2]);
	sphere->color = validate_and_parse_rgb(split[3]);
	free_split(split);
	return (sphere);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:59:40 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:18:51 by tsishika         ###   ########.fr       */
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

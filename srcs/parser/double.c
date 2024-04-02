/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:17:28 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 05:11:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_double(char *str)
{
	size_t	i;
	bool	is_dot;

	is_dot = false;
	i = 0;
	if (str == NULL || *str == '\0')
		return (false);
	if (*str == '-')
		str++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (is_dot)
				return (false);
			is_dot = true;
		}
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

double	validate_and_parse_double(char *str)
{
	if (!is_double(str))
		print_error_and_exit("Invalid double");
	return (ft_atof(str));
}

double	validate_and_parse_double_range(char *str, double min, double max)
{
	double	value;

	value = validate_and_parse_double(str);
	if (!is_in_range_double(value, min, max))
		print_error_and_exit("Invalid range of double");
	return (value);
}

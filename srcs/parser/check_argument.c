/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:40:34 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 21:05:17 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_argument_count(int argc)
{
	if (argc != 2)
		return (false);
	return (true);
}

static bool	check_argument_file_name(char *argv)
{
	if (!ft_strrchr(argv, '.'))
		return (false);
	if (ft_strncmp(ft_strrchr(argv, '.'), ".rt", 3))
		return (false);
	if (strcmp(argv, ".rt") == 0)
		return (false);
	return (true);
}

void	check_argument(int argc, char **argv)
{
	if (!check_argument_count(argc))
		print_error_and_exit("Invalid argument count\n");
	if (!check_argument_file_name(argv[1]))
		print_error_and_exit("Invalid file name\n");
}


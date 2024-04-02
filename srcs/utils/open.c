/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:18:16 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 21:26:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_and_exit_if_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (0 <= fd)
	{
		close(fd);
		print_error_with_context_and_exit(file, ERR_DIRECTORY);
	}
}

int	open_file_and_return_descriptor(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_perror_and_exit(file);
	return (fd);
}

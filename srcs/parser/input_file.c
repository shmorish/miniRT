/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:35:17 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 23:27:07 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	parse_line(char *line)
{
	if (ft_strncmp(line, "A", 1) == 0)
		printf("A\n");
	else if (ft_strncmp(line, "C", 1) == 0)
		printf("C\n");
	else if (ft_strncmp(line, "L", 1) == 0)
		printf("L\n");
	else if (ft_strncmp(line, "sp", 2) == 0)
		printf("sp\n");
	else if (ft_strncmp(line, "pl", 2) == 0)
		printf("pl\n");
	else if (ft_strncmp(line, "cy", 2) == 0)
		printf("cy\n");
	else
		print_error_and_exit(ERR_UNKNOWN);
}

void	input_file(t_data *data, char *argv)
{
	char	*line;
	int		fd;

	(void)data;
	fd = open_file_and_return_descriptor(argv);
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		parse_line(line);
		free(line);
	}
}

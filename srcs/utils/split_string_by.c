/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string_by.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:10:00 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:21:21 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*replace_whitespace_with_single_space(char *line)
{
	char	*modified_line;
	size_t	i;

	modified_line = ft_strdup(line);
	if (modified_line == NULL)
		print_error_and_exit(ERR_MALLOC);
	i = 0;
	while (modified_line[i])
	{
		if (ft_isspace(modified_line[i]))
			modified_line[i] = ' ';
		i++;
	}
	return (modified_line);
}

char	**split_string_by_whitespace(char *line)
{
	char	**split;
	char	*modified_line;

	modified_line = replace_whitespace_with_single_space(line);
	split = ft_split(modified_line, ' ');
	if (split == NULL)
		print_error_and_exit(ERR_MALLOC);
	free(modified_line);
	return (split);
}

char	**split_string_by_comma(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (split == NULL)
		print_error_and_exit(ERR_MALLOC);
	return (split);
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

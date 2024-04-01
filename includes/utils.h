/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:31:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:15:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include "libft.h"

# define ERR_DIRECTORY "is a directory"
# define ERR_MALLOC "malloc failed"

# define ERR_RGB_RANGE "RGB values must be between 0 and 255"
# define ERR_RGB_ARGS "RGB values must have 3 arguments"

// open.c
void	check_and_exit_if_directory(char *file);
int		open_file_and_return_descriptor(char *file);

// print_error.c
void	print_error(char *str);
void	print_perror(char *str);
void	print_error_and_exit(char *str);
void	print_perror_and_exit(char *str);
void	print_error_with_context_and_exit(char *str1, char *str2);

// split_string_by_whitespace.c
char	**split_string_by_whitespace(char *line);
size_t	count_split(char **split);
void	free_split(char **split);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:31:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 21:26:58 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include "libft.h"

#define ERR_DIRECTORY "is a directory"

// open.c
void	check_and_exit_if_directory(char *file);
int		open_file_and_return_descriptor(char *file);

// print_error.c
void	print_error(char *str);
void	print_perror(char *str);
void	print_error_and_exit(char *str);
void	print_perror_and_exit(char *str);
void	print_error_with_context_and_exit(char *str1, char *str2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:27:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 23:09:20 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "struct.h"

# define ERR_ARGC "Invalid number of arguments"
# define ERR_ARGV "Invalid file name"
# define ERR_UNKNOWN "Invalid object type"

// check_argument.c
void	check_argument(int argc, char **argv);

// input_file.c
void	input_file(t_data *data, char *argv);

// parser.c
void	parser(t_data *data, int argc, char **argv);

#endif

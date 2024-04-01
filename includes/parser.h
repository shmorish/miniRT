/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:27:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 01:27:30 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "struct.h"

# define AMBIENT_LIGHTNING "A"
# define CAMERA "C"
# define LIGHT "L"
# define SPHERE "sp"
# define PLANE "pl"
# define CYLINDER "cy"

# define ERR_ARGC "Invalid number of arguments"
# define ERR_ARGV "Invalid file name"
# define ERR_UNKNOWN "Invalid object type"

# define ERR_AL_RATIO "Ambient lightning ratio must be between 0 and 1"
# define ERR_AL_ARGC "Ambient lightning must have 3 arguments"
# define ERR_AL_DUPLICATE "Duplicate ambient lightning"

// ambient_lightning.c
t_ambient_lightning	ambient_lightning(t_is_set *is_set, char *line);

// check_argument.c
void				check_argument(int argc, char **argv);

// input_file.c
void				input_file(t_data *data, char *argv);

// parser.c
void				parser(t_data *data, int argc, char **argv);

#endif

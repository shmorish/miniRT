/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:27:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 05:20:06 by tsishika         ###   ########.fr       */
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

// ambient_lightning
# define ERR_AL_ARGC "Ambient lightning must have 3 arguments"
# define ERR_AL_DUPLICATE "Duplicate ambient lightning"

// camera
# define ERR_CAMERA_ARGC "Camera must have 4 arguments"
# define ERR_CAMERA_DUPLICATE "Duplicate camera"

// ambient_lightning.c
t_ambient_lightning	ambient_lightning(t_is_set *is_set, char *line);

// camera.c
t_camera			camera(t_is_set *is_set, char *line);

// check_argument.c
void				check_argument(int argc, char **argv);

// double.c
bool				is_double(char *str);
double				validate_and_parse_double(char *str);
double				validate_and_parse_double_range(char *str,
						double min, double max);

// is_split_count.c
size_t				count_split(char **split);
void				is_split_count(char **split,
						size_t expected, char *err_msg);

// input_file.c
void				input_file(t_data *data, char *argv);

// is_in_range.c
bool				is_in_range_double(double value, double min, double max);
bool				is_in_range_int(int value, int min, int max);

// parser.c
void				parser(t_data *data, int argc, char **argv);

// rgb.c
int					validate_and_parse_rgb(char *str);

// vector.c
t_vector			validate_and_parse_vector(char *str);
t_vector			validate_and_parse_vector_range(char *str,
						double min, double max);

#endif

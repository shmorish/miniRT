/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:27:53 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 21:08:09 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>

# define ERR_ARGC "Invalid number of arguments"
# define ERR_ARGV "Invalid file name"

// check_argument.c
void	check_argument(int argc, char **argv);

// parser.c
void	parser(int argc, char **argv);

#endif

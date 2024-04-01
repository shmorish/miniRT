/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:28:54 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 01:11:20 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parser(t_data *data, int argc, char **argv)
{
	check_argument(argc, argv);
	check_and_exit_if_directory(argv[1]);
	input_file(data, argv[1]);
}

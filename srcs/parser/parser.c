/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:28:54 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 21:20:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parser(int argc, char **argv)
{
	check_argument(argc, argv);
	check_and_exit_if_directory(argv[1]);
	ft_printf("parser!\n");
}

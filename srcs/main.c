/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:26:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/01 23:24:38 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parser(&data, argc, argv);
}

// int main()
// {
// 	data_init
// 	parser
// 	render
// }

// #ifdef DEBUG

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q miniRT");
}

// #endif

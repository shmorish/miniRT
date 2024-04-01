/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:26:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 00:32:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	test(t_data *data)
{
	printf("ambient_lightning\n");
	printf("ratio: %f\n", data->ambient_lightning.ratio);
	printf("red: %d\n", data->ambient_lightning.color.red);
	printf("green: %d\n", data->ambient_lightning.color.green);
	printf("blue: %d\n", data->ambient_lightning.color.blue);
}

int	main(int argc, char **argv)
{
	t_data	data;

	parser(&data, argc, argv);
	test(&data);
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

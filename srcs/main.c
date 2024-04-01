/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:26:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 04:14:00 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	test(t_data *data)
{
	const int	red = data->ambient_lightning.color >> 16 & 0xFF;
	const int	green = data->ambient_lightning.color >> 8 & 0xFF;
	const int	blue = data->ambient_lightning.color & 0xFF;

	printf("ambient lightning\n");
	printf("ratio: %f\n", data->ambient_lightning.ratio);
	printf("color: %d\n", data->ambient_lightning.color);
	printf("color: %d %d %d\n", red, green, blue);

	printf("camera\n");
	printf("origin: %f %f %f\n", data->camera.origin.x, data->camera.origin.y, data->camera.origin.z);
	printf("direction: %f %f %f\n", data->camera.direction.x, data->camera.direction.y, data->camera.direction.z);
	printf("fov: %f\n", data->camera.fov);
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

#ifdef DEBUG

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q miniRT");
}

#endif

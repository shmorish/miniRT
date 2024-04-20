/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:26:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/10 23:42:51 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_ambient_lightning(t_data *data)
{
	const int	red = data->ambient_lightning.color >> 16 & 0xFF;
	const int	green = data->ambient_lightning.color >> 8 & 0xFF;
	const int	blue = data->ambient_lightning.color & 0xFF;

	ft_printf("ambient lightning\n");
	ft_printf("ratio: %f\n", data->ambient_lightning.ratio);
	ft_printf("color: %d\n", data->ambient_lightning.color);
	ft_printf("color: %d %d %d\n", red, green, blue);
}

void	print_camera(t_data *data)
{
	ft_printf("camera\n");
	ft_printf("coordinate: %f %f %f\n", data->camera.coordinate.x,
		data->camera.coordinate.y, data->camera.coordinate.z);
	ft_printf("direction: %f %f %f\n", data->camera.direction.x,
		data->camera.direction.y, data->camera.direction.z);
	ft_printf("fov: %f\n", data->camera.fov);
}

void	print_light(t_data *data)
{
	const int	red = data->light.color >> 16 & 0xFF;
	const int	green = data->light.color >> 8 & 0xFF;
	const int	blue = data->light.color & 0xFF;

	ft_printf("light\n");
	ft_printf("position: %f %f %f\n", data->light.position.x,
		data->light.position.y, data->light.position.z);
	ft_printf("ratio: %f\n", data->light.ratio);
	ft_printf("color: %d\n", data->light.color);
	ft_printf("color: %d %d %d\n", red, green, blue);
}

int	main(int argc, char **argv)
{
	t_data	data;

	parser(&data, argc, argv);
	print_ambient_lightning(&data);
	print_camera(&data);
	print_light(&data);
	print_object(&data);
	render(&data);
	free_object_list(data.object);
}

#ifdef DEBUG

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q miniRT");
}

#endif

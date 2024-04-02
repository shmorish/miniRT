/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:26:51 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/02 08:51:15 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_ambient_lightning(t_data *data)
{
	const int	red = data->ambient_lightning.color >> 16 & 0xFF;
	const int	green = data->ambient_lightning.color >> 8 & 0xFF;
	const int	blue = data->ambient_lightning.color & 0xFF;

	printf("ambient lightning\n");
	printf("ratio: %f\n", data->ambient_lightning.ratio);
	printf("color: %d\n", data->ambient_lightning.color);
	printf("color: %d %d %d\n", red, green, blue);
}

void	print_camera(t_data *data)
{
	printf("camera\n");
	printf("coordinate: %f %f %f\n", data->camera.coordinate.x,
		data->camera.coordinate.y, data->camera.coordinate.z);
	printf("direction: %f %f %f\n", data->camera.direction.x,
		data->camera.direction.y, data->camera.direction.z);
	printf("fov: %f\n", data->camera.fov);
}

void	print_light(t_data *data)
{
	const int	red = data->light.color >> 16 & 0xFF;
	const int	green = data->light.color >> 8 & 0xFF;
	const int	blue = data->light.color & 0xFF;

	printf("light\n");
	printf("position: %f %f %f\n", data->light.position.x,
		data->light.position.y, data->light.position.z);
	printf("ratio: %f\n", data->light.ratio);
	printf("color: %d\n", data->light.color);
	printf("color: %d %d %d\n", red, green, blue);
}

void	print_sphere(t_sphere *sphere)
{
	const int	red = sphere->color >> 16 & 0xFF;
	const int	green = sphere->color >> 8 & 0xFF;
	const int	blue = sphere->color & 0xFF;

	printf("sphere\n");
	printf("coordinate: %f %f %f\n", sphere->coordinate.x,
		sphere->coordinate.y, sphere->coordinate.z);
	printf("diameter: %f\n", sphere->diameter);
	printf("color: %d\n", sphere->color);
	printf("color: %d %d %d\n", red, green, blue);
}

void	print_plane(t_plane *plane)
{
	const int	red = plane->color >> 16 & 0xFF;
	const int	green = plane->color >> 8 & 0xFF;
	const int	blue = plane->color & 0xFF;

	printf("plane\n");
	printf("coordinate: %f %f %f\n", plane->coordinate.x,
		plane->coordinate.y, plane->coordinate.z);
	printf("direction: %f %f %f\n", plane->direction.x,
		plane->direction.y, plane->direction.z);
	printf("color: %d\n", plane->color);
	printf("color: %d %d %d\n", red, green, blue);
}

void	print_cylinder(t_cylinder *cylinder)
{
	const int	red = cylinder->color >> 16 & 0xFF;
	const int	green = cylinder->color >> 8 & 0xFF;
	const int	blue = cylinder->color & 0xFF;

	printf("cylinder\n");
	printf("coordinate: %f %f %f\n", cylinder->coordinate.x,
		cylinder->coordinate.y, cylinder->coordinate.z);
	printf("direction: %f %f %f\n", cylinder->direction.x,
		cylinder->direction.y, cylinder->direction.z);
	printf("diameter: %f\n", cylinder->diameter);
	printf("height: %f\n", cylinder->height);
	printf("color: %d\n", cylinder->color);
	printf("color: %d %d %d\n", red, green, blue);
}

void	print_object(t_data *data)
{
	t_object	*node;

	node = data->object->next;
	while (node != NULL)
	{
		if (node->type == SPHERE_TYPE)
			print_sphere(node->object_data);
		else if (node->type == PLANE_TYPE)
			print_plane(node->object_data);
		else if (node->type == CYLINDER_TYPE)
			print_cylinder(node->object_data);
		else
			print_error_and_exit(ERR_UNKNOWN);
		node = node->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	parser(&data, argc, argv);
	print_ambient_lightning(&data);
	print_camera(&data);
	print_light(&data);
	print_object(&data);
	free_object_list(data.object);
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

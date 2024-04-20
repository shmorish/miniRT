/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:42:13 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/10 23:43:43 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_sphere(t_sphere *sphere)
{
	const int	red = sphere->color >> 16 & 0xFF;
	const int	green = sphere->color >> 8 & 0xFF;
	const int	blue = sphere->color & 0xFF;

	ft_printf("sphere\n");
	ft_printf("coordinate: %f %f %f\n", sphere->coordinate.x,
		sphere->coordinate.y, sphere->coordinate.z);
	ft_printf("diameter: %f\n", sphere->diameter);
	ft_printf("color: %d\n", sphere->color);
	ft_printf("color: %d %d %d\n", red, green, blue);
}

void	print_plane(t_plane *plane)
{
	const int	red = plane->color >> 16 & 0xFF;
	const int	green = plane->color >> 8 & 0xFF;
	const int	blue = plane->color & 0xFF;

	ft_printf("plane\n");
	ft_printf("coordinate: %f %f %f\n", plane->coordinate.x,
		plane->coordinate.y, plane->coordinate.z);
	ft_printf("direction: %f %f %f\n", plane->direction.x,
		plane->direction.y, plane->direction.z);
	ft_printf("color: %d\n", plane->color);
	ft_printf("color: %d %d %d\n", red, green, blue);
}

void	print_cylinder(t_cylinder *cylinder)
{
	const int	red = cylinder->color >> 16 & 0xFF;
	const int	green = cylinder->color >> 8 & 0xFF;
	const int	blue = cylinder->color & 0xFF;

	ft_printf("cylinder\n");
	ft_printf("coordinate: %f %f %f\n", cylinder->coordinate.x,
		cylinder->coordinate.y, cylinder->coordinate.z);
	ft_printf("direction: %f %f %f\n", cylinder->direction.x,
		cylinder->direction.y, cylinder->direction.z);
	ft_printf("diameter: %f\n", cylinder->diameter);
	ft_printf("height: %f\n", cylinder->height);
	ft_printf("color: %d\n", cylinder->color);
	ft_printf("color: %d %d %d\n", red, green, blue);
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

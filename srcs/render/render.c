/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 03:18:14 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/03 04:04:54 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	render(t_data *data)
{
	my_mlx_init(data);
	mlx_hook(data->mlx->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, &close_window, data);
	mlx_loop(data->mlx->mlx);
}

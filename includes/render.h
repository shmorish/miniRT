/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 03:18:31 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/03 04:03:31 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include "struct.h"

// hook.c
int		key_press(int keycode, t_data *data);
int		close_window(t_data *data);

// init.c
void	my_mlx_init(t_data *data);

// my_mlx_pixel_put.c

// render.c
void	render(t_data *data);

#endif

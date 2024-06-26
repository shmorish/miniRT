/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:27:50 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/10 23:43:04 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <float.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/param.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <time.h>

# include "render.h"
# include "struct.h"
# include "libft.h"
# include "parser.h"
# include "utils.h"
# include "vector.h"
# include "ray.h"

void	print_object(t_data *data);

#endif

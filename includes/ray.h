#ifndef RAY_H
#define RAY_H

#include "miniRT.h"



t_vector	getCameraRay(t_data *data, int x, int y);
void    put_pixel(t_data *data, t_vector camera_ray, int x, int y);

#endif
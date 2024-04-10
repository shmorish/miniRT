#ifndef RAY_H
#define RAY_H

#include "miniRT.h"



t_vector	getCameraRay(t_data *data, int x, int y);
void    put_pixel(t_data *data, t_vector camera_ray, int x, int y);
t_float_rgb	getShineRate(t_data *data, t_object *node, t_vector ray, const double t);
double	hit_plane(t_vector ray, t_vector camera_pos, t_vector obj_pos, t_vector obj_dir);
double	hit_cylinder(t_vector ray, t_vector start_pos, t_cylinder *cylinder);
t_vector	obtainObjectCoordinates(t_object *node);
t_vector	get_normal_cylinder(t_vector intersection_pos, t_object *node);
double	objectCollotion(t_vector start_pos, t_object *head, t_vector ray, t_object **obj);
double	hit_sphere(t_vector ray, t_vector camera_pos, t_vector obj_pos, double radius);

#endif
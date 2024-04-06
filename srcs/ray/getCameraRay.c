#include "miniRT.h"

t_vector    normalize(t_vector v)
{
    double	magnitude;

    magnitude = sqrt(dot_product(v, v));
    return ((t_vector){v.x / magnitude, v.y / magnitude, v.z / magnitude});
}

t_vector	getCameraRay(t_data *data, int x, int y)
{
    t_vector	camera_ray;
    double	aspect_ratio;
    double	scale;
    double	x_offset;
    double	y_offset;

    aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
    scale = tan(deg_to_rad(data->camera.fov) / 2);
    x_offset = (2 * ((x + 0.5) / WINDOW_WIDTH) - 1) * aspect_ratio * scale;
    y_offset = (1 - 2 * ((y + 0.5) / WINDOW_HEIGHT)) * scale;
    camera_ray = (t_vector){x_offset, y_offset, -1};
    camera_ray = normalize(camera_ray);
    return (camera_ray);
}
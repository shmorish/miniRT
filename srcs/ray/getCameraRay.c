#include "miniRT.h"

typedef struct s_screen
{
	t_vector	up;
	t_vector	screen_x;
	t_vector	screen_y;
	double		camera_to_screen;
	double		f_x;
	double		f_y;
	double		w_s;
	double		h_s;
}t_screen;

t_vector	check_screen_up(t_vector v)
{
	if (v.x == 0 && (v.y == 1 || v.y == -1) && v.z == 0)
		return (t_vector){0.0, 0.0, -1.0};
	else
		return (t_vector){0.0, 1.0, 0.0};
}

static t_screen screen_init(int x, int y, t_data *data)
{
    t_screen	screen;
    const t_vector camera_dir = data->camera.direction;

	screen.up = check_screen_up(camera_dir);
    screen.screen_x = cross_product(screen.up, camera_dir);
    screen.screen_y = cross_product(camera_dir, screen.screen_x);
    screen.w_s = 2.0;
    screen.h_s = WINDOW_HEIGHT / WINDOW_WIDTH * screen.w_s;
    screen.camera_to_screen = screen.w_s / (2.0 * tan(data->camera.fov * M_PI / 360.0));
	screen.f_x = (screen.w_s * (double)x) / (WINDOW_WIDTH) - screen.w_s / 2.0;
	screen.f_y = (-screen.h_s * (double)y) / (WINDOW_HEIGHT) + screen.h_s / 2.0;
    return (screen);
}

t_vector	getCameraRay(t_data *data, int x, int y)
{
    const t_screen  screen = screen_init(x, y, data);
    const t_vector  camera_dir = rayObjCrossPos(data->camera.coordinate, screen.camera_to_screen, data->camera.direction);
    const t_vector  coordinate = rayObjCrossPos(rayObjCrossPos(camera_dir, screen.f_x, screen.screen_x), screen.f_y, screen.screen_y);
    return (subtraction(coordinate, data->camera.coordinate));
}

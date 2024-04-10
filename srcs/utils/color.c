#include "miniRT.h"

t_rgb    integer_to_rgb(int color)
{
    t_rgb   rgb;

    rgb.red = (color >> 16) & 0xFF;
    rgb.green = (color >> 8) & 0xFF;
    rgb.blue = color & 0xFF;
    return (rgb);
}

int  transColor(int red, int green, int blue)
{
    return ((red << 16) | (green << 8) | blue);
}

#define COLOR 255.0 /* colorの範囲 */

double	color_to_fcolor(double color)
{
	return (color / COLOR);
}


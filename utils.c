#include "fdf.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
        char    *dst;

		if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGTH || y < 0)
			return ;
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

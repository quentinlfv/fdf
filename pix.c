#include "fdf.h"

int put_pix(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	data->map.reset = 0;
	while (i < data->map.count_y)
	{
		y = WIN_HEIGTH / 4 + data->map.reset * SPACE;
		x = WIN_WIDTH / 3 - data->map.reset * SPACE;
		j = 0;
		while (j + 1 < data->map.count_x)
		{
			dda_alg(data, x, y - (data->map.mapint[i][j] * SPACE / 8), x + SPACE, (y + SPACE / 2) - (data->map.mapint[i][j + 1] * SPACE / 8));
			//my_mlx_pixel_put(data, x, y, 0x00FF0000);
			x += SPACE;
			y += SPACE / 2;
			j++;
		}
		i++;
		data->map.reset += 1;
	}
	i = 0;
	data->map.reset = 0;
	while (i < data->map.count_x)
	{
		y = WIN_HEIGTH / 4 + data->map.reset * (SPACE / 2);
		x = WIN_WIDTH / 3 + data->map.reset * SPACE;
		j = 0;
		while (j + 1< data->map.count_y)
		{
			dda_alg(data, x, y - (data->map.mapint[j][i] * SPACE / 8), x - SPACE, (y + SPACE) - (data->map.mapint[j + 1][i] * SPACE / 8));
			//my_mlx_pixel_put(data, x, y, 0x00FF0000);
			x -= SPACE;
			y += SPACE;
			j++;
		}
		i++;
		data->map.reset += 1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}
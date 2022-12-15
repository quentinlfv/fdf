#include "fdf.h"

void	dda_alg(t_data *data, float x1, float y1, float x2, float y2)
{
	int	i;

	data->line.dx = x2 - x1;
	data->line.dy = y2 - y1;
	if (abs(data->line.dx) > abs(data->line.dy))
		data->line.step = abs(data->line.dx);
	else
		data->line.step = abs(data->line.dy);
	data->line.xinc = data->line.dx / data->line.step;
	data->line.yinc = data->line.dy / data->line.step;
	i = 0;
	while (i < data->line.step)
	{	
		//printf("x1 = %f | y1 = %f | step = %d | x2 = %f | y2 = %f | dy = %f | yinc = %f\n", x1, y1, data->line.step, x2, y2, data->line.dy, data->line.yinc);
		my_mlx_pixel_put(data, round(x1), roundf(y1), 0x00FF0000);
		x1 = x1 + data->line.xinc;
		y1 = y1 + data->line.yinc;
		i++;
	}
}
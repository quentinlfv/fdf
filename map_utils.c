#include "fdf.h"

// void	count_x(t_data *data)
// {
// 	int	y;
// 	int x;

// 	y = 0;
// 	while (y < data->map.count_y)
// 	{
// 		x = 0;
// 		while (data->map.map[y][x])
// 		{
// 			x++;
// 		}
// 		y++;
// 	}
// 	data->map.count_x = x;
// 	printf("\n count x = %d\n", data->map.count_x);
// }

int	count_x(char *s_map)
{
	int	count;
	int x;

	x = 0;
	count = 0;
	while (s_map[x] == ' ')
		x++;
	while (s_map[x] != '\n')
	{
		if (s_map[x] == ' ' && s_map[x + 1] != '\n')
		{
			while (s_map[x] == ' ')
				x++;
			count++;
		}
		x++;
	}
	return (count + 1);
}

int	map_limit(t_data *data)
{
	int	min;
	int	max;
	int	y;
	int	x;

	y = 0;
	min = data->map.mapint[y][0];
	max = data->map.mapint[y][0];
	printf("\n count x = %d | count y = %d\n", data->map.count_x, data->map.count_y);
	while (y < data->map.count_y)
	{
		x = 0;
		while (x < data->map.count_x)
		{
			if (data->map.mapint[y][x] > max)
			{
				max = data->map.mapint[y][x];
				printf("max = %d\n", data->map.mapint[y][x]);
			}
			if (data->map.mapint[y][x] < min)
				min = data->map.mapint[y][x];
			x++;
		}
		y++;
	}
	data->map.int_max = max;
	data->map.int_min = min;
	printf("max = %d || min = %d\n", max, min);
	return (0);
}
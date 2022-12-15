#include "fdf.h"

void	free_all(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.count_y)
	{
		free(data->map.mapint[i]);
		i++;
	}
	i = 0;
	while (data->map.map[i])
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	free(data->map.mapint);
	free(data->mlx_ptr);
}

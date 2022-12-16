#include "fdf.h"

t_map	get_maps(char *map_file)
{
	char *map;
	char *line;
	int count_y;
	int	fd;

	count_y = 0;
	map = NULL;
	fd = open_doc(map_file);	
	line = get_next_line(fd);
	// printf("%s \n", line);
	map = ft_strjoin(map, line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			map = ft_strjoin(map, line);
		count_y++;
	}
	printf("%s\n", map);
	// if (line != NULL)
		free(line);
	close_doc(fd);
	return (initialize_maps(map, count_y));
}

t_map	initialize_maps(char *f_map, int y)
{
	t_map	map;
	char **s_map;
	int	i;
	int j = 0;

	map.count_y = y;
	map.count_x = count_x(f_map);
	printf("count x = %d\n", map.count_x);
	map.map = malloc(sizeof(char **) * map.count_y);
	s_map = ft_split(f_map, '\n');
	i = 0;
	while (i < map.count_y)
	{
		map.map[i] = ft_split(s_map[i], ' ');
		i++;
	}
	i = 0;
	// while (map.map[i])
	// {
	// 	j = 0;
	// 	while (map.map[i][j])
	// 	{
	// 		printf("%s ", map.map[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	i = 0;
	while (i < map.count_y)
	{
		free(s_map[i]);
		i++;
	}
	free(s_map);
	free(f_map);
	return (map);
}

int atoi_map(t_data *data)
{
	int	**int_map;
	int	y;
	int	x;

	y = 0;
	printf("count_y = %d | count_x = %d\n", data->map.count_y, data->map.count_x);
	int_map = malloc(sizeof(int *) * data->map.count_y);
	if (!int_map)
		return (0);
	while (y < data->map.count_y)
	{
		int_map[y] = malloc(sizeof(int) * data->map.count_x);
		if (!int_map)
			return (0);
		y++;
	}
	y = 0;
	while (y < data->map.count_y)
	{
		x = 0;
		while (x < data->map.count_x)
		{
			// printf("Y_VAL== %d\nI_VAL== %d\nATOI_RES== %d\nX_VAL== %d\n\n", y, i, ft_atoi(data->map.map[i]), x);
			int_map[y][x] = ft_atoi(data->map.map[y][x]);
			x++;
		}
		// printf("y = %d\n", y);
		y++;
	}
	printf("\n\n\n");
	y = 0;
	while (y < data->map.count_y)
	{
		x = 0;
		while (x < data->map.count_x)
		{
			printf("%d ", int_map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	data->map.mapint = int_map;
	map_limit(data);
	return (1);
}

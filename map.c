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
	if (line != NULL)
		free(line);
	close_doc(fd);
	return (initialize_maps(map, count_y));
}

// t_map	initialize_maps(char *s_map, int y)
// {
// 	t_map	map;
// 	char **demi_map;
// 	int	i;

// 	map.count_y = y;
// 	map.map = malloc(sizeof(char **) * map.count_y);
// 	demi_map = ft_split(s_map, '\n');
// 	i = 0;
// 	while (i < map.count_y)
// 	{
// 		map.map[i] = ft_split(demi_map[i], ' ');
// 		i++;
// 	}
// 	free(s_map);
// 	for (int i = 0; i < map.count_y; i++)
// 	{
// 		free(demi_map[i]);
// 	}
// 		free(demi_map);
// 	return (map);
// }

t_map	initialize_maps(char *s_map, int y)
{
	t_map	map;
	int	i;

	map.count_y = y;
	i = 0;

	map.count_x = count_x(s_map);
	map.map = ft_split(s_map, ' ');
	printf("count_y = %d\n", map.count_y);
	while (map.map[i])
	{
		printf("%s ", map.map[i]);
		i++;
	}
	free(s_map);
	return (map);
}

int atoi_map(t_data *data)
{
	int	**int_map;
	int	y;
	int	x;
	int i;


	i = 0;
	y = 0;
	printf("count_y = %d\n", data->map.count_y);
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
	printf("map 1000 == %s\n", data->map.map[9992]);
	while (y < data->map.count_y)
	{
		x = 0;
		// printf("%d\n", data->map.count_x);
		while (x < data->map.count_x)
		{
			// printf("Y_VAL== %d\nI_VAL== %d\nATOI_RES== %d\nX_VAL== %d\n\n", y, i, ft_atoi(data->map.map[i]), x);
			int_map[y][x] = ft_atoi(data->map.map[i]);
			x++;
			i++;
			// if (x + 1 > data->map.count_x - 1)
			// 	break ;
			// printf("x = %d | i = %d\n", x, i);
		}
		// printf("y = %d\n", y);
		y++;
		i--;
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

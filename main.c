#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
        char    *dst;

        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	//if (mlx_ptr == NULL)
	//	return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "42");
	//if (win_ptr == NULL)
	//{
	//	free(mlx_ptr);
	//	return(0);
	//}

	data.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.map = get_maps(av[1]);
	atoi_map(&data);
	put_pixel(&data);

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free(data.map.map);
	return (0);
}

t_map	get_maps(char *map_file)
{
	char *map;
	char *line;
	int count_y;
	int	fd;

	count_y = 0;
	map = NULL;
	fd = open_doc(map_file);
	while (line = get_next_line(fd))
	{
		map = ft_strjoin(map, line);
		count_y++;
	}
	close_doc(fd);
	free(line);
	return (initialize_maps(map, count_y));
}

t_map	initialize_maps(char *s_map, int y)
{
	t_map	map;
	char **demi_map;
	int	i;

	map.count_y = y;
	map.map = malloc(sizeof(char **) * map.count_y);
	demi_map = ft_split(s_map, '\n');
	i = 0;
	while (i < map.count_y)
	{
		map.map[i] = ft_split(demi_map[i], ' ');
		i++;
	}
	free(s_map);
	free(demi_map);
	//printf("\n%c\n", map.map[2][2][1]);
	return (map);
}

int	put_pixel(t_data *data)
{
	int	y;
	int x;

	y = 0;
	printf("\n\n");
	while (y < data->map.count_y)
	{
		x = 0;
		while (data->map.map[y][x])
		{
			printf("%s ", data->map.map[y][x]);
			my_mlx_pixel_put(data, ((x - y) * 10) + 1920 / 2, (((x + y) / 2) * 10) + 1080 / 2, 0x00FF0000);
			x++;
		}
		printf("\n");
		y++;
	}
	data->map.count_x = x;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int atoi_map(t_data *data)
{
	int	**int_map;
	int	y;
	int	x;

	y = 0;
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
			int_map[y][x] = ft_atoi(data->map.map[y][x]);
			x++;
		}
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

int	map_limit(t_data *data)
{
	int	min;
	int	max;
	int	y;
	int	x;

	y = 0;
	min = data->map.mapint[y][0];
	max = data->map.mapint[y][0];
	while (y < data->map.count_y)
	{
		x = 0;
		while (x < data->map.count_x)
		{
			if (data->map.mapint[y][x] > max)
				max = data->map.mapint[y][x];
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
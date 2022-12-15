#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_arg(av[1]))
		return (0);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "42");
	data.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.map = get_maps(av[1]);
	atoi_map(&data);
	put_pix(&data);
	printf(" atoi hexa = %d\n", ft_atoi("103,0xffffff"));
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &samibg, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free_all(&data);
	return (0);
}


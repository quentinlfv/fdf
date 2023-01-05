#include "fdf.h"

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == '-')
		printf("yo\n");
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->img)
			mlx_destroy_image(data->mlx_ptr, data->img);
	}
	return (0);
}

int samibg(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free_all(data);
	exit(0);
	return (0);
}

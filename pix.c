/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:09:40 by qlefevre          #+#    #+#             */
/*   Updated: 2023/01/06 14:09:44 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	put_pix(t_data *data)
{
	int	y;
	int	i;
	int	j;

	pix_x(data, y, i, j);
	pix_y(data, y, i, j);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

void	pix_x(t_data *data, int y, int i, int j)
{
	i = 0;
	data->map.reset = 0;
	while (i < data->map.count_y)
	{
		y = (WIN_HEIGTH - (data->map.count_y * SPACE)) / 2
			+ data->map.reset * SPACE;
		data->line.x = (WIN_WIDTH - (data->map.count_x * SPACE)) / 2
			- data->map.reset * SPACE;
		j = 0;
		while (j + 1 < data->map.count_x)
		{
			dda_alg(data, y - (data->map.mapint[i][j] * SPACE / 4),
				data->line.x + SPACE, (y + SPACE / 2)
				- (data->map.mapint[i][j + 1] * SPACE / 4));
			data->line.x += SPACE;
			y += SPACE / 2;
			j++;
		}
		i++;
		data->map.reset += 1;
	}
}

void	pix_y(t_data *data, int y, int i, int j)
{
	i = 0;
	data->map.reset = 0;
	while (i < data->map.count_x)
	{
		y = (WIN_HEIGTH - (data->map.count_y * SPACE)) / 2
			+ data->map.reset * (SPACE / 2);
		data->line.x = (WIN_WIDTH - (data->map.count_x * SPACE)) / 2
			+ data->map.reset * SPACE;
		j = 0;
		while (j + 1 < data->map.count_y)
		{
			dda_alg(data, y - (data->map.mapint[j][i] * SPACE / 4),
				data->line.x - SPACE, (y + SPACE)
				- (data->map.mapint[j + 1][i] * SPACE / 4));
			data->line.x -= SPACE;
			y += SPACE;
			j++;
		}
		i++;
		data->map.reset += 1;
	}
}

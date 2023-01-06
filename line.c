/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:10:10 by qlefevre          #+#    #+#             */
/*   Updated: 2023/01/06 14:10:14 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	dda_alg(t_data *data, float y, float x1, float y1)
{
	int		i;
	float	x;

	x = data->line.x;
	data->line.dx = x1 - x;
	data->line.dy = y1 - y;
	if (abs(data->line.dx) > abs(data->line.dy))
		data->line.step = abs(data->line.dx);
	else
		data->line.step = abs(data->line.dy);
	data->line.xinc = data->line.dx / data->line.step;
	data->line.yinc = data->line.dy / data->line.step;
	i = 0;
	while (i < data->line.step)
	{	
		my_mlx_pixel_put(data, round(x), roundf(y) / 2, 0x00FF9933);
		x = x + data->line.xinc;
		y = y + data->line.yinc;
		i++;
	}
}

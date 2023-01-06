/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:08:20 by qlefevre          #+#    #+#             */
/*   Updated: 2023/01/06 14:08:27 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	free_all(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.count_y)
	{
		j = 0;
		free(data->map.mapint[i]);
		while (j < data->map.count_x)
		{
			free(data->map.map[i][j]);
			j++;
		}
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	free(data->map.mapint);
	free(data->mlx_ptr);
}

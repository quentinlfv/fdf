/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:09:26 by qlefevre          #+#    #+#             */
/*   Updated: 2023/01/06 14:09:30 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	count_x(char *s_map)
{
	int	count;
	int	x;

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

int	map_limit(t_data *data, int y, int x)
{
	int	min;
	int	max;

	min = data->map.mapint[y][0];
	max = data->map.mapint[y][0];
	while (y < data->map.count_y)
	{
		x = 0;
		while (x < data->map.count_x)
		{
			if (data->map.mapint[y][x] > max)
			{
				max = data->map.mapint[y][x];
			}
			if (data->map.mapint[y][x] < min)
				min = data->map.mapint[y][x];
			x++;
		}
		y++;
	}
	data->map.int_max = max;
	data->map.int_min = min;
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * sign);
}

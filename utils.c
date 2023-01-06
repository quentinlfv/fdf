/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:10:27 by qlefevre          #+#    #+#             */
/*   Updated: 2023/01/06 17:02:09 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGTH || y < 0)
		return ;
	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	open_doc(char *doc)
{
	int	fd;

	fd = open(doc, O_RDONLY);
	if (fd == -1)
	{
		ft_putchar("Error while oppening doc");
		return (0);
	}
	return (fd);
}

int	close_doc(int fd)
{
	if (close(fd) < 0)
	{
		ft_putchar("Error while closing doc");
		return (0);
	}
	else
		ft_putchar("closed the doc\n");
	return (1);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char			*ptr;
	unsigned int	i;
	int				a;

	ptr = (char *)s1;
	i = 0;
	a = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			a = strcmmp(s1, s2, i);
			if (ft_strlen(s2) + i > n)
				a = 1;
			if (a == 0)
				return (ptr + i);
		}
		i++;
	}
	return (NULL);
}

static int	strcmmp(const char *s1, const char *s2, int i)
{
	int	j;

	j = 0;
	while (s2[j] == s1[i] && s2[j] && s1[j])
	{
		i++;
		j++;
	}
	if (s2[j] != 0)
		return (s1[i] - s2[j]);
	return (s1[i -1] - s2[j - 1]);
}

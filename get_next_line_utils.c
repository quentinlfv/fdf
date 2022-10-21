/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:57:46 by qlefevre          #+#    #+#             */
/*   Updated: 2022/09/07 16:30:19 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	int				srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (srclen);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}

void	ft_bzero(void *s, size_t n)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < (int)n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strjoin_gnl(char *s1, char *s2, int len_stash)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (len_stash + ft_strlen(s2) + 1));
	if (!s1)
	{
		s1 = malloc (sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!str || !s1 || !s2)
		return (free(s1), free(str), (NULL));
	i = -1;
	j = -1;
	while (++i < len_stash)
		str[i] = s1[i];
	while (++j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = 0;
	ft_bzero(s2, ft_strlen(s2));
	return (free(s1), (str));
}

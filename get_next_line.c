/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:21:16 by qlefevre          #+#    #+#             */
/*   Updated: 2022/10/03 17:21:01 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_findchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

char	*get_line(char *stash, char *buf, int size)
{
	char	*line;
	int		nl;
	int		len_stash;

	len_stash = ft_strlen(stash);
	nl = ft_findchr(stash, '\n');
	if (size == 0 && len_stash == 0)
		return (NULL);
	if (nl != 0 || stash[0] == '\n')
	{
		line = malloc (sizeof(char) * nl + 2);
		if (!line)
			return (NULL);
		ft_strlcpy(line, stash, nl + 2);
		if (stash[nl + 1])
			ft_strlcpy(buf, &stash[nl + 1], len_stash);
	}
	else
	{
		line = malloc (sizeof(char) * len_stash + 1);
		if (!line)
			return (NULL);
		ft_strcpy(line, stash);
	}
	return (line);
}		

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*stash;
	char		*line;
	int			size;

	size = BUFFER_SIZE;
	line = NULL;
	stash = NULL;
	stash = ft_strjoin_gnl(stash, buf, ft_strlen(stash));
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (size == BUFFER_SIZE && ft_findchr(stash, '\n') == 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (free(stash), (NULL));
		buf[size] = 0;
		stash = ft_strjoin_gnl(stash, buf, ft_strlen(stash));
	}
	line = get_line(stash, buf, size);
	if (line == NULL)
		return (free(stash), (NULL));
	free(stash);
	return (line);
}		

// int	main(void)
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("big_line_no_nl", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error while oppening doc");
// 		return (0);
// 	}
// 	printf("the file descp is %d\n", fd);
// 	for (int i = 0; i < 10; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("gnl = %s\n", line);
// 		free(line);
// 	}
// 	if (close(fd) < 0)
// 		printf("Error while closing doc");
// 	else
// 		printf("\nclosed the doc");
// 	return (0);
// }

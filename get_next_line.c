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

char	*get_line(char *mem_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!mem_line[i])
		return (NULL);
	while (mem_line[i] && mem_line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	if (mem_line[i] == '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	get_rest(char *mem_line, char *buf)
{
	size_t	i;

	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
	i++;
	if (i < ft_strlen(mem_line))
		ft_strlcpy(buf, mem_line + i + 1, ft_strlen(mem_line) - i + 1);
	free(mem_line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*mem_line;
	char			*line;
	ssize_t			ret;

	ret = 1;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	mem_line = NULL;
	mem_line = ft_strjoin_gnl(mem_line, buf);
	while (!ft_strchr(mem_line, '\n') && ret != 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return free(mem_line), (NULL);
		mem_line = ft_strjoin_gnl(mem_line, buf);
		if (!mem_line)
			return (NULL);
	}
	line = get_line(mem_line);
	get_rest(mem_line, buf);
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

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	else
		str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

static int	strnbr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str = malloc(sizeof(char *) * (strnbr(s, c) + 1));
	if (!str)
		return (NULL);
	while (i < strnbr(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j])
		{
			k++;
			j++;
		}
		str[i++] = ft_substr(s, (j - k), k);
		k = 0;
	}
	str[i] = NULL;
	return (str);
}

int open_doc(char *doc)
{
    int	fd;

	fd = open(doc , O_RDONLY);
	if (fd == -1)
	{
		printf("Error while oppening doc");
		return (0);
	}
	printf("fd = %d\n", fd);
    return (fd);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

int close_doc(int fd)
{
    if (close(fd) < 0)
    {
		printf("Error while closing doc");
        return (0);
    }
	else
		printf("closed the doc\n");
    return (1);
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
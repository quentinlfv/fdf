#include "fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	free((void *)s1);
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
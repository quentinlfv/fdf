#include "fdf.h"

int check_arg(char *file)
{
    if (ft_strnstr(file, ".fdf", ft_strlen(file)) == NULL)
        return (0);
    return (1);
}
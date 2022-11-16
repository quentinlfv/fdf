#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 750

typedef	struct s_map
{
	char	***map;
	int		count_y;
	int		count_x;
	int		**mapint;
	int		int_min;
	int		int_max;
}t_map;

typedef struct	s_data
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map 	map;
}t_data;



/* main.c */

void	ft_putchar(char c);
int		handle_no_event(void *data);
int		handle_keypress(int key, t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_map	get_maps(char *map_file);
t_map	initialize_maps(char *s_map, int y);
int		put_pixel(t_data *data);
int 	atoi_map(t_data *data);
int		map_limit(t_data *data);
void	count_x(t_data *data);
int 	samibg(t_data *data);


/* get_next_line */

void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
int		ft_findchr(char *str, char c);
char	*ft_strjoin_gnl(char *s1, char *s2, int len_stash);
char	*get_line(char *stash, char *buf, int size);
char	*get_next_line(int fd);

/* functions.c */

char	*ft_substr(char const *s, unsigned int start, size_t len);
static int	strnbr(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int 	open_doc(char *doc);
int		close_doc(int fd);
int	ft_atoi(const char *nptr);

#endif
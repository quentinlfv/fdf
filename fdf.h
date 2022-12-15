#ifndef FDF_H
# define FDF_H

# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define BUFFER_SIZE 1500000
# define SPACE 30
# define WIN_HEIGTH 1080
# define WIN_WIDTH 1920


typedef struct s_line
{
	float	dx;
	float	dy;
	float	step;
	float	xinc;
	float	yinc;
}t_line;

typedef	struct s_map
{
	char	**map;
	int		reset;
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
	t_line	line;
}t_data;



/* main.c */

void	ft_putchar(char c);
int		handle_no_event(void *data);
int		handle_keypress(int key, t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_map	get_maps(char *map_file);
t_map	initialize_maps(char *s_map, int y);
int 	put_pix(t_data *data);
int 	atoi_map(t_data *data);
int		map_limit(t_data *data);
int	count_x(char *s_map);
int 	samibg(t_data *data);
void	dda_alg(t_data *data, float x1, float y1, float x2, float y2);
void	free_all(t_data *data);
int 	check_arg(char *file);




/* get_next_line */

void	ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
void	get_rest(char *mem_line, char *buf);
char	*ft_strjoin_gnl(char *mem_line, char *buf);
char	*get_line(char *mem_line);
char	*get_next_line(int fd);

/* functions.c */

char	*ft_substr(char const *s, unsigned int start, size_t len);
static int	strnbr(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int 	open_doc(char *doc);
int		close_doc(int fd);
int	ft_atoi(const char *nptr);
static int	strcmmp(const char *s1, const char *s2, int i);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

#endif

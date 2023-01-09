/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:31:54 by qlefevre          #+#    #+#             */
/*   Updated: 2023/01/06 17:31:59 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define SPACE 8
# define WIN_HEIGTH 1440
# define WIN_WIDTH 2560

typedef struct s_line
{
	float	x;
	float	dx;
	float	dy;
	float	step;
	float	xinc;
	float	yinc;
}t_line;

typedef struct s_map
{
	char	***map;
	int		reset;
	int		count_y;
	int		count_x;
	int		**mapint;
	int		int_min;
	int		int_max;
}t_map;

typedef struct s_data
{
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
	t_line	line;
}t_data;

/* check.c */
int			check_arg(char *file);

/* free.c */
void		free_all(t_data *data);

/* handle_event.c */
int			handle_no_event(void *data);
int			handle_keypress(int key, t_data *data);
int			handle_cross(t_data *data);

/* map.c */
t_map		get_maps(char *map_file);
t_map		initialize_maps(char *f_map, int y);
int			malloc_map(t_data *data);
void		atoi_map(t_data *data, int **int_map, int y, int x);

/* map_utils.c */
int			count_x(char *s_map);
int			map_limit(t_data *data, int y, int x);
int			ft_atoi(const char *nptr);

/* line.c */
void		dda_alg(t_data *data, float y, float x1, float y1);

/* pix.c */
void		put_pix(t_data *data);
void		pix_x(t_data *data, int y, int i, int j);
void		pix_y(t_data *data, int y, int i, int j);

/* get_next_line.c */

void		get_rest(char *mem_line, char *buf);
char		*get_line(char *mem_line);
char		*get_next_line(int fd);

/* get_next_line_utils.c */
void		ft_bzero(void *s, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, char const *src, size_t size);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin_gnl(char *mem_line, char *buf);

/* functions.c */
void		ft_putchar(char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
static int	strnbr(char const *s, char c);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);

/* utils.c */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			open_doc(char *doc);
int			close_doc(int fd);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
static int	strcmmp(const char *s1, const char *s2, int i);

#endif

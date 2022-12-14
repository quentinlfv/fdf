NAME = fdf

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra 



SRCS		= main.c \
				functions.c \
				free.c \
				handle_event.c \
				line.c \
				map.c \
				map_utils.c \
				pix.c \
				utils.c \
				check.c \
				get_next_line.c \
				get_next_line_utils.c \

OBJS		= $(SRCS:.c=.o)

RM 			:= rm -rf

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:

	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: 
		$(MAKE) fclean
		$(MAKE) all

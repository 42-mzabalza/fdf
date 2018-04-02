
NAME = fdf

LIBFT = libft/libft.a

CC = clang

FLAGS = -Wall -Werror -Wextra -I./includes

SRC = srcs/get_next_line.c\
		srcs/fdf.c\
		srcs/print_line.c\
		srcs/show_usage.c\
		srcs/print_2dmap.c

OBJ		= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework Appkit -o $(NAME)
clean:
	/bin/rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean
	make

.PHONY: clean fclean re all

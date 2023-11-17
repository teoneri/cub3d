NAME = cub3D

CC = gcc

CFLAGS = -Werror -Wextra -Wall -I minilibx -L mlx -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRCS = SRC/main.c SRC/map_checker.c  SRC/map_valid.c SRC/controls.c SRC/drawmap.c

OBJS			= $(SRCS:.c=.o)

$(NAME) : ${SRCS}
	$(MAKE) -C Libft/
	$(MAKE) -C mlx/
	$(MAKE) clean -C Libft/
	gcc $(CFLAGS) $(SRCS) Libft/libft.a -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make clean -C mlx
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C mlx
	make clean -C libft

re : fclean all

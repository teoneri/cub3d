NAME = cub3D

SRC = SRC/main.c SRC/map_checker.c  SRC/map_valid.c SRC/drawmap.c SRC/raycast.c SRC/draw.c

LINKS = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm

SRC_OBJ = $(SRC:.c=.o)

LIB = Libft/libft.a

FLAGS = -Wall -Wextra -Werror -fPIE -fPIC -g
all : $(NAME)

$(NAME): $(SRC_OBJ) $(HEAD)
	$(MAKE) -C Libft/
	$(MAKE) -C minilibx-linux/
	$(MAKE) clean -C Libft/
	@gcc $(FLAGS) $(SRC_OBJ) $(LIB) $(LINKS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: all
        
clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C Libft/
	$(MAKE) clean -C minilibx-linux/
re: fclean all
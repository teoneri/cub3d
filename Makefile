NAME = cub3D

SRC = SRC/main.c SRC/map_checker.c  SRC/map_valid.c SRC/raycast.c SRC/draw.c SRC/utils.c SRC/player_move.c SRC/controls.c SRC/player_camera.c SRC/free.c \
	SRC/color_texture.c SRC/draw_ceil_floor.c SRC/map_checker2.c

LINKS = minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm

SRC_OBJ = $(SRC:.c=.o)

LIB = Libft/libft.a

FLAGS = -Wall -Wextra -Werror -fPIE -fPIC -O0 -g
all : $(NAME)

$(NAME): $(SRC_OBJ) $(HEAD)
	$(MAKE) -C Libft/
	$(MAKE) -C minilibx-linux/
	$(MAKE) clean -C Libft/
	@gcc $(FLAGS) $(SRC_OBJ) $(LIB) $(LINKS) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I/usr/include -Imlx_linux -O0 -c $< -o $@

bonus: all
        
clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C Libft/
	$(MAKE) clean -C minilibx-linux/
re: fclean all
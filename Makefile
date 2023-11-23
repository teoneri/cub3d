NAME = cub3D

SRC = SRC/main.c SRC/map_checker.c  SRC/map_valid.c SRC/drawmap.c SRC/raycast.c SRC/draw.c

CFLAGS = -Werror -Wextra -Wall -I minilibx -L mlx -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRCS = SRC/main.c SRC/utils.c SRC/map_checker.c  SRC/map_valid.c SRC/controls.c SRC/drawmap.c SRC/player_move.c

FLAGS = -Wall -Wextra -Werror -fPIE -fPIC -g3 -O0
all : $(NAME)

$(NAME) : ${SRCS}
	$(MAKE) -C Libft/
	$(MAKE) -C mlx/
	$(MAKE) clean -C Libft/
	@gcc $(FLAGS) $(SRC_OBJ) $(LIB) $(LINKS) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

bonus: all
        
clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C Libft/
	$(MAKE) clean -C minilibx-linux/
re: fclean all
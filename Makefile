#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := cub3d
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      SRC/main.c \
                          SRC/map_checker.c \
                          Libft/ft_toupper.c \
                          Libft/ft_tolower.c \
                          Libft/ft_split.c \
                          Libft/ft_memcpy.c \
                          Libft/ft_lstsize.c \
                          Libft/ft_strnstr.c \
                          Libft/ft_isalnum.c \
                          Libft/ft_strlcat.c \
                          Libft/ft_strchr.c \
                          Libft/ft_lstiter.c \
                          Libft/ft_isdigit.c \
                          Libft/ft_itoa.c \
                          Libft/ft_lstclear.c \
                          Libft/ft_strlcpy.c \
                          Libft/ft_strrchr.c \
                          Libft/ft_isprint.c \
                          Libft/ft_isascii.c \
                          Libft/ft_lstadd_front.c \
                          Libft/ft_strjoin.c \
                          Libft/ft_lstmap.c \
                          Libft/ft_striteri.c \
                          Libft/ft_strncmp.c \
                          Libft/ft_putchar_fd.c \
                          Libft/ft_memset.c \
                          Libft/ft_strlen.c \
                          Libft/ft_atoi.c \
                          Libft/ft_strmapi.c \
                          Libft/ft_lstlast.c \
                          Libft/ft_bzero.c \
                          Libft/ft_substr.c \
                          Libft/ft_putstr_fd.c \
                          Libft/ft_strdup.c \
                          Libft/ft_isalpha.c \
                          Libft/ft_lstdelone.c \
                          Libft/ft_lstnew.c \
                          Libft/ft_memchr.c \
                          Libft/ft_memmove.c \
                          Libft/ft_lstadd_back.c \
                          Libft/ft_putendl_fd.c \
                          Libft/ft_putnbr_fd.c \
                          Libft/ft_strtrim.c \
                          Libft/ft_memcmp.c \
                          Libft/ft_calloc.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      SRC/main.c \
                          SRC/map_checker.c \
                          minilibx-linux/mlx_mouse_hook.c \
                          minilibx-linux/mlx_int_param_event.c \
                          minilibx-linux/mlx_loop.c \
                          minilibx-linux/mlx_int_anti_resize_win.c \
                          minilibx-linux/mlx_hook.c \
                          minilibx-linux/mlx_screen_size.c \
                          minilibx-linux/mlx_rgb.c \
                          minilibx-linux/mlx_clear_window.c \
                          minilibx-linux/mlx_xpm.c \
                          minilibx-linux/mlx_get_color_value.c \
                          minilibx-linux/mlx_set_font.c \
                          minilibx-linux/mlx_destroy_window.c \
                          minilibx-linux/mlx_expose_hook.c \
                          minilibx-linux/mlx_mouse.c \
                          minilibx-linux/mlx_ext_randr.c \
                          minilibx-linux/mlx_new_window.c \
                          minilibx-linux/mlx_get_data_addr.c \
                          minilibx-linux/mlx_destroy_display.c \
                          minilibx-linux/mlx_lib_xpm.c \
                          minilibx-linux/mlx_new_image.c \
                          minilibx-linux/mlx_int_wait_first_expose.c \
                          minilibx-linux/mlx_put_image_to_window.c \
                          minilibx-linux/mlx_init.c \
                          minilibx-linux/test/new_win.c \
                          minilibx-linux/test/main.c \
                          minilibx-linux/mlx_int_do_nothing.c \
                          minilibx-linux/mlx_int_str_to_wordtab.c \
                          minilibx-linux/mlx_string_put.c \
                          minilibx-linux/mlx_flush_event.c \
                          minilibx-linux/mlx_int_set_win_event_mask.c \
                          minilibx-linux/mlx_pixel_put.c \
                          minilibx-linux/mlx_destroy_image.c \
                          minilibx-linux/mlx_key_hook.c \
                          minilibx-linux/mlx_int_get_visual.c \
                          minilibx-linux/mlx_loop_hook.c \
                          Libft/ft_toupper.c \
                          Libft/ft_tolower.c \
                          Libft/ft_split.c \
                          Libft/ft_memcpy.c \
                          Libft/ft_lstsize.c \
                          Libft/ft_strnstr.c \
                          Libft/ft_isalnum.c \
                          Libft/ft_strlcat.c \
                          Libft/ft_strchr.c \
                          Libft/ft_lstiter.c \
                          Libft/ft_isdigit.c \
                          Libft/ft_itoa.c \
                          Libft/ft_lstclear.c \
                          Libft/ft_strlcpy.c \
                          Libft/ft_strrchr.c \
                          Libft/ft_isprint.c \
                          Libft/ft_isascii.c \
                          Libft/ft_lstadd_front.c \
                          Libft/ft_strjoin.c \
                          Libft/ft_lstmap.c \
                          Libft/ft_striteri.c \
                          Libft/ft_strncmp.c \
                          Libft/ft_putchar_fd.c \
                          Libft/ft_memset.c \
                          Libft/ft_strlen.c \
                          Libft/ft_atoi.c \
                          Libft/ft_strmapi.c \
                          Libft/ft_lstlast.c \
                          Libft/ft_bzero.c \
                          Libft/ft_substr.c \
                          Libft/ft_putstr_fd.c \
                          Libft/ft_strdup.c \
                          Libft/ft_isalpha.c \
                          Libft/ft_lstdelone.c \
                          Libft/ft_lstnew.c \
                          Libft/ft_memchr.c \
                          Libft/ft_memmove.c \
                          Libft/ft_lstadd_back.c \
                          Libft/ft_putendl_fd.c \
                          Libft/ft_putnbr_fd.c \
                          Libft/ft_strtrim.c \
                          Libft/ft_memcmp.c \
                          Libft/ft_calloc.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re

NAME	=	miniRT

DIR_HEADERS	=	./includes/

DIR_SRCS =	./srcs/

DIR_OBJS = ./obj/

LIBFT	=	libft.a
LIBMLX	=	libmlx.dylib

INCLUDES = -I $(DIR_HEADERS) -I $(LIBFT) -I $(LIBMLX)

SRC		=	error_exit.c \
			vector.c \
			scene.c camera.c \
			sphere.c \
			triangle.c \
			ray_trace.c \
			sphere_intersect.c \
			color_convert.c \
			mlx.c \
			main.c

$(shell mkdir -p $(DIR_OBJS))

OBJS	= 	$(addprefix $(DIR_OBJS), $(SRC:.c=.o))
			

CC		=	gcc
RM		=	rm -f
CFLAGS 	=	-Wall -Wextra -Werror

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./minilibx_mms_20200219
			cp ./minilibx_mms_20200219/libmlx.dylib .
			make -C ./mylib
			cp ./mylib/libft.a .
			$(CC) $(CFLAGS) -I $(DIR_HEADERS) $(LIBFT) $(LIBMLX) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:	
		rm -f $(OBJS)

fclean:	clean
			rm -rf $(DIR_OBJS)
			make clean -C ./minilibx_mms_20200219
			$(RM) $(LIBMLX)
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	clean fclean re all
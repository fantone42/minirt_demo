DIR_HEADERS	=	./includes/

DIR_SRCS =	./srcs/

			
SRC		=	utils/error_exit.c \
			geometry/vector.c \
			scene/scene.c scene/camera.c \
			figures/sphere.c \
			ray_tracing/ray_trace.c \
			intersections/sphere_intersect.c \
			main.c

SRCS	=	$(addprefix $(DIR_SRCS), $(SRC))

OBJS	=	$(SRCS:.c=.o)

NAME	=	miniRT

LIBMLX	=	libmlx.dylib

CC		=	gcc
RM		=	rm -f
CFLAGS 	=	-Wall -Wextra -Werror

%.o: %.c
			$(CC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
			make -C ./minilibx_mms_20200219
			cp ./minilibx_mms_20200219/libmlx.dylib .
			$(CC) $(CFLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:	
		$(RM) $(OBJS)

fclean:	clean
			make clean -C ./minilibx_mms_20200219
			$(RM) $(LIBMLX)
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	clean fclean re all
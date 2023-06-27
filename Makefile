.PHONY:     			all $(NAME) clear mkbuild lib clear clean fclean re sanitize

NAME					= cub3D

BUILD_DIR				= build/

HEADER_DIR				= header/

HEADER_FILES				= header/cub.h header/typedef.h

DIR						= src/

SRC			 			=	main.c	init.c	utils.c	keypress.c	free.c\
							parsing/parsing.c	parsing/colors.c	parsing/check_map.c parsing/lst_utils.c\
							mlx.c \
							raycasting/draw_minimap.c		raycasting/move.c\
							raycasting/refresh.c	raycasting/draw_rays.c\
							raycasting/raycasting.c  raycasting/texture.c \
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)

LIBFT					= libft.a
LIB_DIR					= libft/



CC						= cc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	# Mac_os
    MINILIB_DIR			= minilibx_macos/
	MINILIB_FLAGS		= -framework OpenGL -framework AppKit 
else
    # Linux
    MINILIB_DIR			= minilibx_linux/
    MINILIB_FLAGS 		= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz 
endif	

MINILIB					= libmlx.a

$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADER_FILES} ${LIB_DIR}*.c ${LIB_DIR}/${LIB_HEADER} ${LIB_DIR} Makefile 
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					clear lib mkbuild minilibx $(HEADER_DIR) $(NAME)

go:						all
						./${NAME} map.cub

mkbuild:	
						@mkdir -p ${BUILD_DIR}

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(MINILIB_FLAGS)

sanitize :				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(MINILIB_FLAGS)

lib:
						@make -C $(LIB_DIR) --no-print-directory
	
minilibx:
						@make -C $(MINILIB_DIR) --no-print-directory

clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR) --no-print-directory
						@make clean -C $(MINILIB_DIR) --no-print-directory
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR) --no-print-directory

re:						fclean all
						$(MAKE) all
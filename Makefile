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
							raycasting/refresh.c
							

							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)

LIBFT					= libft.a
LIB_DIR					= libft/
	
CC						= cc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

# MINILIB_DIR			= minilibx_macos/
# MAC					= -framework OpenGL -framework AppKit 

MINILIB_DIR				= minilibx_linux/
LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz 

$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADER_FILES} ${LIB_DIR}*.c ${LIB_DIR}/${LIB_HEADER} ${LIB_DIR} Makefile 
						@mkdir -p $(@D)
						$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					clear lib mkbuild minilibx $(HEADER_DIR) $(NAME)
	
mkbuild:	
						@mkdir -p ${BUILD_DIR}

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

sanitize :				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(CC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

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
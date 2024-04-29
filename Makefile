<<<<<<< HEAD
NAME = cub3d
CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLXFLAGS	=	-L ./minilibx -lmlx -Ilmlx -lXext -lX11
MINILIBX_PATH	=	./minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
SRC = main.c get_next_line.c lib_utils.c parsing_dir.c parsing_map.c

OBJ = $(SRC:%.c=%.o)
=======
NAME			= cub3d
CC				= cc
FLAGS			= -Wall -Werror -Wextra
MLXFLAGS		= -Lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz #-lminilibx-linux
MINILIBX_PATH	= ./minilibx-linux
MINILIBX		= $(MINILIBX_PATH)/libmlx.a
SRC				= main.c get_next_line.c lib_utils.c parsing_dir.c parsing_map.c \
				utils.c

OBJ				= $(SRC:%.c=%.o)
>>>>>>> 3862364 (limpeza do codigo)

###################COLOR CODES#############################

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CLEARBLUE	= \033[1;94m
CYAN 		= \033[1;36m
PURPLE		= \033[1;35m
WHITE 		= \033[1;37m
BLACK 		= \033[1;30m
GREY 		= \033[0;37m

###########################################################

all: ${NAME}

${NAME}: $(OBJ)
	$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
<<<<<<< HEAD
	$(CC) $(FLAGS) -lm $(SRC) $(MLXFLAGS) -o $(NAME)
	@rm *.o
=======
	$(CC) $(FLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)
>>>>>>> 3862364 (limpeza do codigo)
	@clear
	@echo "$(GREEN)Compilation of ${CLR_RMV}${CYAN}$(NAME) ${CLR_RMV}$(GREEN)"
	@echo "$(CYAN)$(NAME) ${CLR_RMV}$(GREEN)created with sucess ${CLR_RMV} "

<<<<<<< HEAD
=======
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

>>>>>>> 3862364 (limpeza do codigo)
clean:
	@rm -rf $(OBJ)
	@echo "$(RED)Deleting $(PURPLE)-> $(YELLOW)$(NAME) $(CLR_RMV)$(RED)[objs]$(GREEN) ${CLR_RMV}"

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean all

run: re
<<<<<<< HEAD
	@./cub3d
=======
	@./cub3d maps/mapvalid.cub
>>>>>>> 3862364 (limpeza do codigo)

.PHONY: all clean fclean re run

NAME			= cub3d
CC				= cc
FLAGS			= -Wall -Werror -Wextra -fsanitize=address
MLXFLAGS		= minilibx-linux/libmlx.a -lXext -lX11 -lm
MINILIBX_PATH	= minilibx-linux
MINILIBX		= $(MINILIBX_PATH)/libmlx.a
SRC				= srcs/2drays.c srcs/get_next_line.c srcs/leave.c srcs/lib_utils.c \
				srcs/main.c srcs/moves.c srcs/parsing_dir.c srcs/parsing_map.c srcs/utils.c \
				srcs/rays.c
INCLUDES		=
OBJ				= $(SRC:%.c=%.o)

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

all: minilibx ${NAME}

minilibx:
	make -C minilibx-linux/

${NAME}: $(OBJ)
	@$(MAKE) --no-print-directory -C $(MINILIBX_PATH)
	@clear
	$(CC) $(FLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation of ${CLR_RMV}${CYAN}$(NAME) ${CLR_RMV}$(GREEN)"
	@echo "$(CYAN)$(NAME) ${CLR_RMV}$(GREEN)created with sucess ${CLR_RMV} "

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@ 

clean:	
	@rm -rf $(OBJ)
	@echo "$(RED)Deleting $(PURPLE)-> $(YELLOW)$(NAME) $(CLR_RMV)$(RED)[objs]$(GREEN) ${CLR_RMV}"

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean all

run: re
	@./cub3d maps/mapvalid.cub

.PHONY: all clean fclean re run

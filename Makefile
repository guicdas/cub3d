NAME = cub3d
CC = cc
FLAGS = -Wall -Werror -Wextra -g
MLXFLAGS	=	-L ./minilibx -lmlx -Ilmlx -lXext -lX11
MINILIBX_PATH	=	./minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
SRC = main.c get_next_line.c lib_utils.c parsing_dir.c parsing_map.c

OBJ = $(SRC:%.c=%.o)

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
	$(CC) $(FLAGS) -lm $(SRC) $(MLXFLAGS) -o $(NAME)
	@rm *.o
	@clear
	@echo "$(GREEN)Compilation of ${CLR_RMV}${CYAN}$(NAME) ${CLR_RMV}$(GREEN)"
	@echo "$(CYAN)$(NAME) ${CLR_RMV}$(GREEN)created with sucess ${CLR_RMV} "

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)Deleting $(PURPLE)-> $(YELLOW)$(NAME) $(CLR_RMV)$(RED)[objs]$(GREEN) ${CLR_RMV}"

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean all

run: re
	@./cub3d

.PHONY: all clean fclean re run

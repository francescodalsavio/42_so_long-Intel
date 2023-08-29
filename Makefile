NAME = so_long
SRCS_DIR = ./src/

SRC = main.c utils/ft_strlen.c utils/show_error.c check_arguments.c \
quit_game.c show_images.c animation.c manage_map.c move_player.c \
utils/get_next_line.c utils/ft_strdup.c utils/ft_itoa.c utils/free.c \
map_checker.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))
FLAGS = -Wall -Werror -Wextra

MLX_MAC = -Lminilibx -lmlx -framework -framework AppKit

LIBRARY := -lmlx -framework OpenGL -framework AppKit
MINILIBX := ./lib/minilibx_mms_20200219/

GFLAGS = -framework OpenGL -framework Appkit -l z
GPATH = ./lib/minilibx_mms_20200219
MLX_PATH = $(GPATH)/libmlx.dylib


BUILD_DIR = ./build
BIN_DIR = ./bin
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MINILIBX)
	mkdir -p $(BIN_DIR)
	gcc $(FLAGS) $(OBJS) $(LIBRARY) -o $(BIN_DIR)/$(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)%.c
	mkdir -p $(dir $@)
	#gcc $(FLAGS) -c $< -o $@
	gcc -c $< -o $@

clean:
	make clean -C $(MINILIBX)
	@rm -rf $(BUILD_DIR)

fclean: clean	
	@rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS = -lX11 -lXext
#-------------------------------------#
LIBFT = libft/libft.a
LIBFT_DIR = libft/
#-------------------------------------#
SOURCE = so_long.c
SOURCE_OBJS = $(SOURCE:.c=.o)
#-------------------------------------#
MINILIBX = minilibx-linux/libmlx_Linux.a
MINILIBX_DIR = minilibx-linux/
#-------------------------------------#
#MINILIBX_OPENGL = minilibx_opengl/libmlx.a
#MINILIBX_OPENGL_DIR = minilibx_opengl/

# Variáveis de texo
GREEN = \033[92m
RESET	= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(SOURCE_OBJS) $(MINILIBX_DIR) $(MINILIBX)
		$(CC) $(FLAGS) $(MINILIBX_FLAGS) -o $(NAME) $(SOURCE_OBJS) $(LIBFT) $(MINILIBX)
	@echo "[$(GREEN)SUCCESS$(RESET)]Compilation successful."

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(MINILIBX_DIR):
	wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz -O minilibx
	tar -xzvf minilibx
	rm minilibx

clean:
	rm -rf $(SOURCE_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "[$(GREEN)SUCCESS$(RESET)]Objects removed."

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	@echo "[$(GREEN)SUCCESS$(RESET)]Static Library and Executables removed."

re: fclean all

.SILENT:

.PHONY: all clean fclean re

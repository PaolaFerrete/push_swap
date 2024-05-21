# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paola <paola@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 18:05:45 by paola             #+#    #+#              #
#    Updated: 2024/05/21 12:22:27 by paola            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# compilation and flag
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
INCLUDE = ./include

# files sources and objects
SRC_FILES = error_free.c \
			split.c \
			push_command.c \
			push_swap_command.c \
			push_swap_init.c \
			reverse_rotate_command.c \
			rotate_command.c \
			stack_utils.c \
			stack_init.c \
			swap_command.c \
			tiny_sort.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

# Libft files
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/lib
LIBFT = libft.a

# Executable
MAIN_DIR = ./prog

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_LIB)/$(LIBFT)
	$(CC) $(CFLAGS) $(MAIN_DIR)/*.c $(OBJ_FILES) -I $(INCLUDE) -o $@ -L $(LIBFT_LIB) -lft

$(LIBFT_LIB)/$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)/*.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

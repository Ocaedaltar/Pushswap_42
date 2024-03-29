# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlormois <mlormois@studient.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 21:34:13 by mlormois          #+#    #+#              #
#    Updated: 2021/12/25 22:12:21 by mlormois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

# **************************************************************************** #

OBJ_DIR		=	objs
INC_DIR		=	incs
SRC_DIR		=	$(shell find srcs -type d)

# **************************************************************************** #

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
SRCS	= $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

# --  Redirection in OBJS  -- #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# --   Compilation flags  -- #
CC			=	clang
CFLAGS		=   -Wall -Wextra -Werror -g3 -fsanitize=address

# **************************************************************************** #

.PHONY: all
all : $(NAME)

# **************************************************************************** #

$(NAME): $(OBJS) $(INC_DIR)/pushswap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INC_DIR)

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/pushswap.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
	mkdir -p $@
	
# **************************************************************************** #

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

# **************************************************************************** #

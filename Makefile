# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 21:04:33 by nchairun          #+#    #+#              #
#    Updated: 2025/03/03 21:36:45 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

LIBFT_DIR	:= ./lib
LIBFT 		:= $(LIBFT_DIR)/libftprintf.a

SRCS		:= $(shell find ./src -iname "*.c")
OBJS		:= $(SRCS:./src/%.c=./build/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

./build/%.o: ./src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(LIBFT_DIR)/build/ft_printf/*.o
	rm -f $(LIBFT_DIR)/build/libft/*.o
    
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
    
re: fclean all

.PHONY: all fclean clean re
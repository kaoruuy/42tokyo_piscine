# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 10:31:05 by kayoshid          #+#    #+#              #
#    Updated: 2026/02/25 20:36:06 by kayoshid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
SRC_DIR = srcs
INC_DIR = includes

SRCS	= $(SRC_DIR)/main.c \
		  $(SRC_DIR)/read_file.c \
		  $(SRC_DIR)/parse.c \
		  $(SRC_DIR)/grid.c \
		  $(SRC_DIR)/solve.c \
		  $(SRC_DIR)/output.c \
		  $(SRC_DIR)/parse_utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

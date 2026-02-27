# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: komori <komori@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 21:24:08 by komori            #+#    #+#              #
#    Updated: 2026/02/22 16:31:53 by komori           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = rush-02
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
SRC_DIR = srcs
INC_DIR = includes

SRCS	= $(SRC_DIR)/check.c \
		  $(SRC_DIR)/display_utils.c \
		  $(SRC_DIR)/display.c \
		  $(SRC_DIR)/find_in_dict.c \
		  $(SRC_DIR)/main.c \
		  $(SRC_DIR)/parsing_utils.c \
		  $(SRC_DIR)/parsing.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

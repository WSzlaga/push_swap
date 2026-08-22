# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/18 07:31:49 by wszlaga           #+#    #+#              #
#    Updated: 2026/08/21 03:00:14 by wszlaga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft
LIB_NAME = ft

CFLAGS += -I$(LIB_DIR)

LDFLAGS = -L$(LIB_DIR) -l$(LIB_NAME)

NAME = push_swap
SRCS = main.c push_op.c rev_rot_op.c rotate_op.c swap_op.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIB_DIR)/lib$(LIB_NAME).a:
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB_DIR)/lib$(LIB_NAME).a
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
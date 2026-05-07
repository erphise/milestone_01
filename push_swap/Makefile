# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/26 10:05:15 by ugutierr          #+#    #+#              #
#    Updated: 2026/05/07 18:35:20 by berhugue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker
TESTER = tester.sh
CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = main.c parse_input.c is_valid_input.c init_env.c push_swap_utils.c\
	print_bench.c print_ops.c lst_to_node.c utils_instructions.c\
	instructions_push.c instructions_reverse_rotate.c \
	instructions_rotate.c instructions_swap.c push_swap.c\
	push_swap_medium.c node_utils.c push_swap_simple.c push_swap_complex.c\
	simple_utils.c
OBJS = $(SRCS:.c=.o)
CHECKER_SRCS = checker.c get_next_line.c get_next_line_utils.c\
	instructions_push.c instructions_reverse_rotate.c \
	instructions_rotate.c instructions_swap.c\
	lst_to_node.c utils_instructions.c\
	parse_input.c is_valid_input.c init_env.c push_swap_utils.c\
	node_utils.c
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
INCLUDES = push_swap.h
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

all: $(NAME)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(LIB) $(CHECKER_OBJS)
	$(CC) $(CHECKER_OBJS) $(LIB) -o $(CHECKER_NAME)

test: $(TESTER) $(NAME)
	bash $(TESTER)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c $(INCLUDES) Makefile
	$(CC) $(FLAGS) -I$(LIB_DIR) -I. -c $< -o $@

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJS)
	rm -f $(CHECKER_OBJS)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)
	rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re

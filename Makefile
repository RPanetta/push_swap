# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpanetta <rpanetta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/11 13:58:04 by rpanetta          #+#    #+#              #
#    Updated: 2026/01/11 13:58:04 by rpanetta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = src/main.c\
src/check_args.c\
src/convert_args.c\
src/duplicates.c\
src/stack_utils.c\
src/utils.c\
operations/push.c\
operations/reverse_rotate.c\
operations/rotate.c\
operations/swap.c\

OBJECTS = $(SOURCES:%.c=%.o)

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -I .

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
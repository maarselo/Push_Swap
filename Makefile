# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 15:14:15 by mvillavi          #+#    #+#              #
#    Updated: 2025/03/16 15:14:17 by mvillavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h
SRCS = free.c positions.c create.c entry.c movements1.c movements2.c error.c sort1.c main.c operationsUtils.c utils.c sort2.c rotates.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR=./Libft
LIBFT=$(LIBFT_DIR)/libft.a

CC = cc -g
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(LIBFT): 
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) $(LIBFT) $(HEADER) Makefile
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
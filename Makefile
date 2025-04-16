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
BNAME = checker

HEADER = push_swap.h

SRCS = free.c positions1.c create.c entry.c movements1.c movements2.c error.c \
		main.c sort1.c operationsUtils.c utils.c sort2.c positions2.c rotates.c
OBJS = $(SRCS:.c=.o)

BHEADER = push_swap_bonus.h
BSRCS= mainBonus.c movementsBonus1.c movementsBonus2.c \
		free.c positions1.c create.c entry.c movements1.c movements2.c \
		error.c sort1.c operationsUtils.c utils.c sort2.c positions2.c rotates.c 

BOBJS = $(BSRCS:.c=.o)

LIBFT_DIR=./Libft
LIBFT=$(LIBFT_DIR)/libft.a

CC = cc -g
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(LIBFT): 
	@echo "$(BLUE)->Compilando Libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) $(LIBFT) $(HEADER) Makefile
	@echo "$(GREEN)✔ Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)	 Compilación completada!$(RESET)"

bonus : $(BNAME)

$(BNAME): $(BOBJS) $(LIBFT) $(HEADER) $(BHEADER) Makefile
	@echo "$(YELLOW)->Compilando el $(BNAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(BOBJS) -L$(LIBFT_DIR) -lft -o $(BNAME)
	@echo "$(YELLOW) Compilación completada!$(RESET)"

clean :
	@echo "$(RED)  Limpiando objetos...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)  Borrando ejecutable ...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

bonusClean: 
	@echo "$(RED)  Limpiando objetos bonus...$(RESET)"
	@$(RM) $(BOBJS)

bonusFclean: bonus_clean
	@echo "$(RED)  Borrando checker bonus...$(RESET)"
	@$(RM) $(BNAME)

re: fclean all

.PHONY: all bonus clean fclean bonusClean bonusFclean re 

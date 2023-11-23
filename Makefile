# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daumis <daumis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 00:23:25 by daumis            #+#    #+#              #
#    Updated: 2023/07/19 15:18:28 by daumis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN		=	src/main.c \
				src/push_swap_utils.c \
				src/ft_split.c \
				src/ft_atoi.c \
				src/checkinputs.c \
				src/ft_memset.c \
				src/actions.c \
				src/actions2.c \
				src/actions3.c \
				src/sort_algo.c \
				src/set_props.c \
				src/free.c

SRCS        = ${SRC_MAIN}
OBJ_DIR     = objs
OBJS        = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC		= cc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror

NAME            = push_swap

all: $(OBJ_DIR) $(OBJS) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@printf '\033[A\033[19C'"⌛ [\e[1;96mCompiling\033[0m]\033[35m $<\033[0m \n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@printf '\033[A\033[20C'"\033[32;1m  ✅ Project has compiled successfully!          \033[0m"
	@printf "\n\n    [🏳️ FLAGS: \033[0;35m$(CFLAGS)\033[0m]"
	@echo "\033[32;1m\n 💾 Executable \e[7m./$(NAME)\e[27m has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

clean:
	$(RM) -r $(OBJ_DIR)

fclean:
	@echo "\033[1;93m\n                        [Cleaning directories with \033[0;96mfclean\033[1;93m]\n\033[0m"
	@make clean
	$(RM) $(NAME)

re:
	@make fclean
	@echo "\033[1;93m\n                             [Calling \033[0;96mmake all\033[1;93m rule]\n\n\033[0m"
	@make -s all

.PHONY: all clean fclean re

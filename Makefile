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

SRCS			=	${SRC_MAIN}

OBJ			=	$(SRCS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	push_swap

all:			$(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;35m\n                              ⌛️Compiling files...\033[0m"
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "\033[32;1m\n                     Project has compiled successfully! ✅ \033[0m"
	@echo "\033[32;1m\n 💾 Executable './$(NAME)' has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"


clean:
	$(RM) $(OBJ)

fclean:
	@echo "\033[1;33m\n                        [Cleaning directories with \033[0;36mfclean\033[1;33m]\n\033[0m"
	@make clean
	$(RM) $(NAME)

re:	
	@make fclean
	@echo "\033[1;33m\n                            [Calling \033[0;36mmake all\033[1;33m rule]\n\033[0m"
	@make -s all

.PHONY:	all clean fclean re

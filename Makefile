# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/09 00:12:48 by ishaimou          #+#    #+#              #
#    Updated: 2019/05/09 00:30:36 by ishaimou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGREEN = \033[1;32m
BCYAN = \033[1;36m
RESET = \033[0m

NAME = ishaimou.filler

LIB_NAME = libft.a

LIB = -L./libft -lft

LIB_DIR = ./libft

H_DIR = ./includes

FLAGS = -Wall -Werror -Wextra

SRCS = craft_piece.c create_hmap.c read_env.c tools.c main.c

SRCS_DIR = $(addprefix srcs/, $(SRCS))

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@echo "$(BGREEN)$(LIB_NAME) has been created successfully.$(RESET)"
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -I $(H_DIR) $(LIB)
	@echo "$(BGREEN)$(NAME) has been created successfully.$(RESET)"

clean:
	@make clean -C $(LIB_DIR)
	@echo "$(BCYAN)Object files has been cleaned successfully.$(RESET)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)
	@echo "$(BCYAN)$(NAME) cleaned successfully.$(RESET)"

re: fclean all

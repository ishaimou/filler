# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/25 05:56:44 by ishaimou          #+#    #+#              #
#    Updated: 2019/05/27 05:20:49 by ishaimou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGREEN = \033[1;32m
BCYAN = \033[1;36m
RESET = \033[0m

NAME = displayer

LIB_NAME = libft.a

LIB_DIR = ../libft

LIBFT = -L ../libft -lft

LIB_SDL2 = -L ~/.brew/Cellar/sdl2/2.0.9_1/lib/ -lSDL2

LIB_SDL2_IMG = -L ~/.brew/Cellar/sdl2_image/2.0.4/lib/ -lSDL2_image

LIB_SDL2_TTF = -L ~/.brew/Cellar/sdl2_ttf/2.0.14/lib/ -lSDL2_ttf

H_DIR = ./includes

H_LIBFT = ../libft

H_SDL2 = ~/.brew/Cellar/sdl2/2.0.9_1/include/SDL2 

H_SDL2_IMG = ~/.brew/Cellar/sdl2_image/2.0.4/include/SDL2 

H_SDL2_TTF = ~/.brew/Cellar/sdl2_ttf/2.0.14/include/SDL2

FLAGS = -Wall -Werror -Wextra

SRCS = init.c parser.c background.c draw.c draw_rect.c main.c\
		event_loop.c result.c events.c get_infos.c tools.c free.c

SRCS_DIR = $(addprefix srcs/, $(SRCS))

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@echo "$(BGREEN)$(LIB_NAME) has been created successfully.$(RESET)"
	@gcc -o $(NAME) $(SRCS_DIR) -I $(H_DIR) -I $(H_LIBFT) -I $(H_SDL2) -I $(H_SDL2_IMG) -I $(H_SDL2_TTF)\
		$(LIBFT) $(LIB_SDL2) $(LIB_SDL2_IMG) $(LIB_SDL2_TTF) $(FLAGS)
	@echo "$(BGREEN)$(NAME) has been created successfully.$(RESET)"

clean:
	@make clean -C $(LIB_DIR)
	@echo "$(BCYAN)Object files has been cleaned successfully.$(RESET)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)
	@echo "$(BCYAN)$(NAME) cleaned successfully.$(RESET)"

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 11:19:09 by rhohls            #+#    #+#              #
#    Updated: 2018/07/09 07:36:32 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rhohls.filler

# Path
SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./libft/
OTHER_PLAYERS = ./resources/players/

# Files
SRC_FILE =	ai.c			\
			basic_moves.c	\
			complex_move.c	\
			generate.c		\
			heat_manip.c	\
			in_board.c		\
			location_decision.c	\
			opp_location.c	\
			piece_trim.c	\
			piece_trim_sides.c	\
			placement.c		\
			playgame.c		\
			printstate.c	\
			valid_move.c	\

OBJ_FILE = $(SRC_FILE:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

#Additional
MAIN ?= main.c
MAINT ?= main_test.c

#Compile
CCFLAGS = -Wall -Werror -Wextra
CC = gcc $(CCFLAGS)

LIBF = $(LIB_PATH)libft.a

#Make Commands
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) -o $@ $(LIBF) $(OBJ) $(MAIN)
	cp $@ $(OTHER_PLAYERS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -I$(INC_PATH) -o $@ -c $<

play: all
	./fill.sh

test: compile
	@make -C $(LIB_PATH)
	@$(CC) -o $@ $(LIBF) $(OBJ) $(MAIN)
	./$(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all test clean




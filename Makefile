# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhohls <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 11:19:09 by rhohls            #+#    #+#              #
#    Updated: 2018/06/28 07:06:13 by rhohls           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rhohls.filler
SRCS = ./sources/
OBJF = ./objects/
CCF = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a

MAIN ?= main.c
MAINT ?= main_test.c

FILES = *.c
OBJS = $(FILES: .c=.o)

$(NAME): compile
	gcc -o $(NAME) $(OBJF)*.o $(LIBFT) $(MAIN)
	#$(OBJF)$(OBJS)

compile: $(OBJ)
	gcc -c $(SRCS)$(FILES)
#	@mv $(SRCS)$(OBJS) $(OBJF)
	mv *.o $(OBJF)

play: all
	./fill.sh

test: compile
	gcc -o $(NAME) $(OBJF)*.o $(LIBFT) $(MAINT)
	./$(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJF)*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all test clean




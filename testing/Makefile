# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 12:53:22 by lde-jage          #+#    #+#              #
#    Updated: 2018/06/14 12:53:24 by lde-jage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

TEST = testing

FLAGS = -Wall -Wextra -Werror

LIB = -lncurses

CC = clang++

MAINSRC = main.c

SRC = file1.c

TESTSRC = test.c

OPT = $(SRC:.cpp=.o)

MAINOPT = $(SRC:.cpp=.o)

TESTOPT = $(SRC:.cpp=.o)

all:
	$(CC) -c $(MAINSRC) $(SRC) $(FLAGS)
	$(CC) -o $(NAME) $(MAINOPT) $(OPT) $(LIB) $(FLAGS)

test:
	$(CC) -c $(TESTSRC) $(SRC) $(FLAGS)
	$(CC) -o $(NAME) $(TESTOPT) $(OPT) $(LIB) $(FLAGS)

clean:
	/bin/rm -f $(OPT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

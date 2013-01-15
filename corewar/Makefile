##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
## 
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
## 
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Mon Oct 22 10:39:42 2012 hugues morisset
##

SRC= 	main.c

OBJ= $(SRC:.c=.o)

NAME= corewar

CFLAGS= -g -pg -Wall -ansi -pedantic -O2 -march=native -Wfloat-equal -Wmissing-include-dirs

INVOCATION= cc

$(NAME):	$(OBJ)
		$(INVOCATION) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

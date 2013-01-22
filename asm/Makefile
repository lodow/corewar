##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Tue Jan 22 14:47:58 2013 maxime lavandier
##

SRC= 	main.c \
	parse.c \
	parse_cmd.c \
	header.c \
	../misc/str_func.c \
	../misc/get_file.c \
	../misc/get_next_line.c

OBJ= $(SRC:.c=.o)

NAME= asm

CFLAGS= -g -pg -Wall -ansi -Wfloat-equal -Wmissing-include-dirs

INVOCATION= cc

$(NAME):	$(OBJ)
		$(INVOCATION) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

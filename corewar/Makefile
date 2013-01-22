##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Tue Jan 15 13:26:45 2013 adrien dellamaggiora
##

SRC= 	main.c \
	champ_load.c \
	get_bin_file.c \
	endianess.c \
	op_utilities.c \
	op/op_live.c \
	../misc/my_memset.c \
	../misc/liste.c \
	../misc/str_func.c \
	../misc/get_file.c \
	../misc/get_next_line.c

OBJ= $(SRC:.c=.o)

NAME= corewar

CFLAGS= -g -pg -Wall -ansi -pedantic -Wfloat-equal -Wmissing-include-dirs

INVOCATION= cc

$(NAME):	$(OBJ)
		$(INVOCATION) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

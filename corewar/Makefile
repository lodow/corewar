##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Wed Jan 23 17:32:39 2013 luc sinet
##

SRC= 	main.c \
	pars_args.c \
	check_args.c \
	champ_load.c \
	get_bin_file.c \
	endianess.c \
	init_vm.c \
	process_util.c \
	op_utilities.c \
	op/op_live.c \
	../misc/nb_func.c \
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

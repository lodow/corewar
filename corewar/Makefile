##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Thu Mar 21 13:11:30 2013 luc sinet
##

SRC= 	main.c \
	pars.c \
	check_args.c \
	pars_args.c \
	check_options.c \
	pars_champ.c \
	champ_load.c \
	get_bin_file.c \
	game.c \
	dump.c \
	init_vm.c \
	process_util.c \
	get_param_instr.c \
	pre_pars.c \
	exec_select.c \
	remake_args.c \
	op/op_useful.c \
	op/op_utilities.c \
	op/op_add.c \
	op/op_aff.c \
	op/op_and.c \
	op/op_fork.c \
	op/op_ldi.c \
	op/op_lfork.c \
	op/op_live.c \
	op/op_lld.c \
	op/op_lldi.c \
	op/op_load.c \
	op/op_or.c \
	op/op_st.c \
	op/op_sti.c \
	op/op_sub.c \
	op/op_xor.c \
	op/op_zjmp.c \
	../misc/endianess.c \
	../misc/nb_func.c \
	../misc/my_memset.c \
	../misc/liste.c \
	../misc/str_func.c \
	../misc/get_file.c \
	../misc/get_next_line.c \
	../misc/my_strdup.c \
	../misc/my_uint64_t_strbase.c \
	../misc/my_str_to_wordtab.c

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

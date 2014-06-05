SRC= 	main.c \
	my_malloc.c \
	parse.c \
	direct.c \
	check_cmd.c \
	parse_cmd.c \
	parsing.c \
	header.c \
	label.c \
	func_label.c \
	chose_func.c \
	get_adresse.c\
	get_adr.c \
	live.c \
	add_sub.c \
	aff.c \
	and_or_xor.c \
	fork.c \
	ld.c \
	ldi.c \
	st.c \
	sti.c \
	zjump.c \
	../misc/str_func.c \
	../misc/get_file.c \
	../misc/endianess.c \
	../misc/get_next_line.c \
	../misc/my_strdup.c \
	../misc/my_memset.c \
	../misc/op.c \
	../misc/nb_func.c

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

re:	fclean	all

NAME= asm/corewar/select

PATHASM= asm
PATHCOR= corewar
PATHSEL= corewar/my_select_bin

all:	$(NAME)

$(NAME):
	make -C $(PATHASM)
	make -C $(PATHCOR)
	make -C $(PATHSEL)

clean:
	make clean -C $(PATHASM)
	make clean -C $(PATHCOR)
	make clean -C $(PATHSEL)

fclean:	clean
	make fclean -C $(PATHASM)
	make fclean -C $(PATHCOR)
	make fclean -C $(PATHSEL)

re:	fclean all

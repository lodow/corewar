##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Sat Mar 30 01:58:20 2013 Hugues
##

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

##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
##
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
##
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Wed Mar 27 00:08:43 2013 Hugues
##

NAME= asm/corewar

PATHASM= asm
PATHCOR= corewar

all:	$(NAME)

$(NAME):
	make -C $(PATHASM)
	make -C $(PATHCOR)

clean:
	make clean -C $(PATHASM)
	make clean -C $(PATHCOR)

fclean:	clean
	make fclean -C $(PATHASM)
	make fclean -C $(PATHCOR)

re:	fclean all

##
## Makefile for Make in /home/moriss_h//afs/rendu/lib/my
## 
## Made by hugues morisset
## Login   <moriss_h@epitech.net>
## 
## Started on  Mon Oct 22 09:20:28 2012 hugues morisset
## Last update Sat Dec  8 21:54:44 2012 Hugues
##

SRC=	main.c \
	transformation.c \
	put_pixel.c \
	handle_mlx.c \
	fdf.c \
	get_next_line.c \
	parse_point.c \
	my_getnbr.c \
	draw_line.c \
	shadows.c \
	free.c

CFLAGS=

OBJ= $(SRC:.c=.o)

LIB= -L/usr/lib64 -lmlx_${HOSTTYPE} -L/usr/lib64/X11 -lXext -lX11

NAME= fdf

INVOCATION= cc

all:	$(NAME)

$(NAME):	$(OBJ)
		cc $(OBJ) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

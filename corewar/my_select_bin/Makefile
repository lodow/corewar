##
## Makefile for copylib in /home/sinet_l//jour11
## 
## Made by luc sinet
## Login   <sinet_l@epitech.net>
## 
## Started on  Mon Oct 22 10:27:19 2012 luc sinet
## Last update Sat Mar 30 01:52:27 2013 luc sinet
##

SRCS	= main.c \
	  attr.c \
	  cmd.c \
	  calc_display.c \
	  match.c \
	  display.c \
	  match_opt.c \
	  occur_opt.c \
	  str.c \
	  nb.c

OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

NAME	= ../my_select

CFLAGS	= -ltermcap

$(NAME): 	$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean
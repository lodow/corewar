/*
** select.h for select in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 15 12:19:58 2013 luc sinet
** Last update Sat Mar 30 01:55:39 2013 luc sinet
*/

#ifndef SEL_H_
# define SEL_H_

#include <termcap.h>
#include <sys/ioctl.h>
#include <unistd.h>

# define UP (buf[0] == 27 && buf[1] == '[' && buf[2] == 'A')
# define DOWN (buf[0] == 27 && buf[1] == '['  && buf[2] == 'B')
# define LEFT (buf[0] == 27 && buf[1] == '['  && buf[2] == 'D')
# define RIGHT (buf[0] == 27 && buf[1] == '[' && buf[2] == 'C')
# define BSPACE (buf[0] == 127)
# define DEL (buf[0] == 27 && buf[1] == '[' && buf[2] == '3' && buf[3] == '~')
# define SPACE (buf[0] == ' ')
# define ENTER (buf[0] == '\n' && buf[1] == '\0')
# define ESC (buf[0] == 27 && buf[1] == '\0')
# define SELECT (buf[0] == 6 && buf[1] == '\0')
# define POS (buf[0] == 24 && buf[1] == '\0')

typedef struct	s_sel
{
  char		**arg;
  char		*state;
  int		*size;
  int		ttyfd;
  int		nb_elem;
  int		max_elem;
  int		pos;
  int		selected;
  int		width;
  int		height;
}		t_sel;

typedef struct	s_dis
{
  int		pos_column;
  int		line;
  int		biggest;
}		t_dis;

typedef struct		s_all
{
  t_sel			*sel;
  t_dis			*dis;
  struct termios	prev;
}		t_all;

#include "nb.h"
#include "str.h"
#include "match_opt.h"

void	change_size();
void	mfree();

#endif

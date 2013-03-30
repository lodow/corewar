/*
** attr.c for attr in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 15 14:37:48 2013 luc sinet
** Last update Sun Jan 20 13:18:36 2013 luc sinet
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include "select.h"

void    load_ent(t_sel *sel , char *opt)
{
  char  *str;

  str = tgetstr(opt, NULL);
  my_putstr(str, sel->ttyfd);
}

void    activate_ent(char state, t_sel *sel)
{
  char  *str;

  load_ent(sel, "ue");
  load_ent(sel, "me");
  if (state == 1 || state == 3)
    load_ent(sel, "us");
  if (state == 2 || state == 3)
    load_ent(sel, "mr");
}

void			change_mod(t_all *g_all, t_sel *sel)
{
  struct termios	t;

  if (tcgetattr(sel->ttyfd, &t) == -1 ||
      tcgetattr(sel->ttyfd, &(g_all->prev)) == -1)
    error(1);
  t.c_lflag &= ~ICANON;
  t.c_lflag &= ~ECHO;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(sel->ttyfd, TCSANOW, &t) == -1)
    error(1);
  load_ent(sel, "vi");
  myclear(g_all);
}

int	fgetent(char **env)
{
  int	i;
  int	res;

  i = 0;
  while (env[i] && my_strncmp(env[i], "TERM=", 5) != 0)
    i += 1;
  res = tgetent(NULL, &((env[i])[5]));
  if (res == -1)
    my_putstr("The termcaps database can't be found\n", 2);
  else if (res == 0)
    my_putstr("Invalid terminal name\n", 2);
  if (res <= 0)
    return (-1);
  return (0);
}

int			get_size(t_sel *sel)
{
  struct winsize	w;

  ioctl(0, TIOCGWINSZ, &w);
  sel->height = w.ws_row;
  sel->width = w.ws_col;
  return 0;
}

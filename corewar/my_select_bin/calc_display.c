/*
** calc_display.c for cacl in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 16 19:17:52 2013 luc sinet
** Last update Sat Jan 19 01:46:38 2013 luc sinet
*/

#include <stdlib.h>
#include "select.h"

extern t_all	*g_all;

int	test_size(t_all *g_all, t_sel *sel, int final_size)
{
  if ((final_size - 3) >= sel->width)
    {
      myclear(g_all);
      return (1);
    }
  return (0);
}

int	too_big(t_all *g_all, t_sel *sel)
{
  int	i;
  int	biggest;
  int	final_size;

  biggest = 0;
  i = 0;
  final_size = 0;
  while (i < sel->max_elem)
    {
      if (sel->state[i] != 4)
	{
	  if (sel->size[i] > biggest)
	    biggest = sel->size[i];
	  if ((i % sel->height - 1) == 0)
	    {
	      final_size += (biggest + 3);
	      biggest = 0;
	    }
	}
      i += 1;
    }
  if (test_size(g_all, sel, final_size))
    return (1);
  return (0);
}

void		cursor_pos(t_sel *sel, t_dis *dis, int i)
{
  char		*str;

  if (sel->size[i] > dis->biggest)
    dis->biggest = sel->size[i];
  if (dis->line - sel->height < 0)
    dis->line += 1;
  else if (dis->line - sel->height >= 0)
    {
      if (dis->line != 0)
	dis->pos_column += (dis->biggest + 3);
      dis->biggest = sel->size[i];
      dis->line = 0;
    }
  str = tgoto(tgetstr("cm", NULL), dis->pos_column, dis->line);
  my_putstr(str, sel->ttyfd);
}

void	change_size()
{
  char  *str;

  myclear(g_all);
  get_size(g_all->sel);
  display(g_all);
}

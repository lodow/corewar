#include <stdlib.h>
#include <signal.h>
#include "select.h"

extern t_all	*g_all;

void	myclear(t_all *g_all)
{
  char	*str;

  str = tgoto(tgetstr("cm", NULL), 0, 0);
  my_putstr(str, g_all->sel->ttyfd);
  load_ent(g_all->sel, "cd");

}

void	display(t_all *g_all)
{
  int	i;

  i = 0;
  if (too_big(g_all, g_all->sel))
    my_putstr("Please increase your window's size", g_all->sel->ttyfd);
  else
    {
      g_all->dis->pos_column = 0;
      g_all->dis->biggest = 0;
      g_all->dis->line = -1;
      while (i < g_all->sel->max_elem)
	{
	  if (g_all->sel->state[i] != 4)
	    {
	      cursor_pos(g_all->sel, g_all->dis, i);
	      activate_ent(g_all->sel->state[i], g_all->sel);
	      my_putstr(g_all->sel->arg[i], g_all->sel->ttyfd);
	    }
	  i += 1;
	}
    }
}

void	init_tab(char *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab[i] = '\0';
      i++;
    }
}

void	init_control(t_sel *sel, char *buf)
{
  signal(SIGWINCH, change_size);
  signal(SIGINT, mfree);
  init_tab(buf, 4);
  get_size(sel);
  display(g_all);
}

void	cmd(t_all *g_all, t_sel *sel, t_dis *dis)
{
  char	buf[4];

  while (1)
    {
      init_control(sel, buf);
      if (read(0, buf, 4) == -1)
	error(2);
      if (ENTER)
      	send_select(g_all, sel);
      else if (ESC)
	{
	  myclear(g_all);
	  mfree();
	}
      else if (SPACE)
	mselect(sel);
      else if (UP || DOWN)
	displacement_verti(sel, buf[2]);
      else if (RIGHT || LEFT)
	displacement_hori(sel, buf[2]);
      else if (DEL || BSPACE)
	sup_elem(g_all, sel);
      else if (SELECT || POS)
      	adds(g_all, sel, buf[0]);
    }
}

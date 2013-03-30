/*
** occur_opt.c for occur in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Jan 19 00:59:03 2013 luc sinet
** Last update Sun Jan 20 16:03:47 2013 luc sinet
*/

#include <stdlib.h>
#include "select.h"
#include "displacement.h"

void    search_occur(t_sel *sel, char *final)
{
  int   i;
  int	n;
  int	hit;

  i = 0;
  hit = 0;
  n = my_strlen(final);
  while (i < sel->max_elem)
    {
      if (sel->state[i] != 4)
	{
	  if (my_strncmp(sel->arg[i], final, n) == 0 && !hit)
	    {
	      if (sel->state[i] == 0 || sel->state[i] == 3)
		sel->state[i] += 1;
	      hit = 1;
	      sel->pos = i;
	    }
	  else if (sel->state[i] >= 1)
	    sel->state[i] -= 1;
	}
      i += 1;
    }
}

void    select_occur(t_all *g_all, t_sel *sel)
{
  char  buf[10];
  char  *final;
  int   let;

  init_tab(buf, 10);
  if ((final = malloc(1)) == NULL)
    error(1);
  final[0] = '\0';
  display_cmd(g_all, sel, final, 1);
  while (!ENTER && !ESC)
    {
      display_cmd(g_all, sel, final, 1);
      init_tab(buf, 10);
      if ((let = read(0, buf, 9)) == -1)
	error(2);
      if (!ENTER && !ESC)
	{
	  if (BSPACE || DEL)
	    final = delete_let(final);
	  else if ((final = my_copie(final, buf, let)) == NULL)
	    error(1);
	  search_occur(sel, final);
	}
    }
  free(final);
}

void     move_pos(t_sel *sel, char sens)
{
  int	sa;

  sa = sel->pos;
  if (sens == 'A')
    {
      while ((sel->state[sel->pos] == 4 || sa == sel->pos) && sel->nb_elem > 1)
	sel->pos = VMINPOS(sel->pos);
    }
  else
    {
      while ((sel->state[sel->pos] == 4 || sa == sel->pos) && sel->nb_elem > 1)
	sel->pos = VMAXPOS(sel->pos);
    }
}

void	adds(t_all *g_all, t_sel *sel, char opt)
{
  load_ent(g_all->sel, "ve");
  if (opt == 24)
    select_matching(g_all, sel);
  else
    select_occur(g_all, sel);
  myclear(g_all);
  display(g_all);
  load_ent(g_all->sel, "vi");
}

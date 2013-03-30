/*
** cmd.c for  in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 15 17:05:26 2013 luc sinet
** Last update Sun Jan 20 16:02:10 2013 luc sinet
*/

#include "select.h"
#include "displacement.h"

int	displacement_verti(t_sel *sel, char sens)
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
  if (sa != sel->pos && sel->state[sel->pos] != 4)
    {
      if (sel->state[sa] != 4)
	sel->state[sa] -= 1;
      sel->state[sel->pos] += 1;
      return (1);
    }
  sel->pos = sa;
  return (0);
}

int	displacement_hori(t_sel *sel, char sens)
{
  int	save;

  save = sel->pos;
  if (sens == 'D')
    {
      sel->pos = HMINPOS(sel->pos);
      if (sel->state[sel->pos] == 4)
	move_pos(sel, 'B');
    }
  else
    {
      sel->pos = HMAXPOS(sel->pos);
      if (sel->state[sel->pos] == 4)
	move_pos(sel, 'A');
    }
  if (save != sel->pos && sel->state[sel->pos] != 4)
    {
      if (sel->state[save] != 4)
  	sel->state[save] -= 1;
      sel->state[sel->pos] += 1;
      return (1);
    }
  sel->pos = save;
  return (0);
}

void	sup_elem(t_all *g_all, t_sel *sel)
{
  myclear(g_all);
  if (sel->state[sel->pos] == 3)
    sel->selected -= 1;
  sel->state[sel->pos] = 4;
  sel->nb_elem -= 1;
  if (sel->nb_elem == 0)
    {
      load_ent(sel, "ue");
      load_ent(sel, "me");
      my_putstr("No more element to display\n", sel->ttyfd);
      mfree();
    }
  if (displacement_verti(sel, 'B') == 0)
    displacement_verti(sel, 'A');
}
void	mselect(t_sel *sel)
{
  if (sel->state[sel->pos] == 3)
    {
      sel->state[sel->pos] -= 2;
      sel->selected -= 1;
    }
  else
    {
      sel->state[sel->pos] += 2;
      sel->selected += 1;
    }
  if (displacement_verti(sel, 'B') == 0)
    displacement_verti(sel, 'A');
}

void	send_select(t_all *g_all, t_sel *sel)
{
  int	i;

  i = 0;
  myclear(g_all);
  load_ent(sel, "ue");
  load_ent(sel, "me");
  while (i < sel->max_elem)
    {
      if (sel->state[i] == 2 || sel->state[i] == 3)
	{
	  my_putstr(sel->arg[i], 1);
	  sel->selected -= 1;
	  if (sel->selected > 0)
	    my_putchar(' ', 1);
	  else
	    my_putchar('\n', 1);
	}
      i += 1;
    }
  mfree();
}

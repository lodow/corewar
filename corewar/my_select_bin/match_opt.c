/*
** options.c for options in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Fri Jan 18 17:59:07 2013 luc sinet
** Last update Sat Jan 19 12:33:45 2013 luc sinet
*/

#include <stdlib.h>
#include "select.h"

char	*my_copie(char *str, char *buf, int s_read)
{
  char  *inter;
  int   size_str;

  if (buf[1])
    return (str);
  size_str = my_strlen(str);
  if (s_read == 0)
    return (str);
  if ((inter = malloc(sizeof(*str) * (size_str + s_read + 1))) == NULL)
    return (NULL);
  if (inter == 0)
    return (NULL);
  inter[0] = '\0';
  my_strcat(inter, str);
  free(str);
  my_strcat(inter, buf);
  return (inter);
}

char	*delete_let(char *str)
{
  if (!str[0])
    return (str);
  str[my_strlen(str) - 1] = '\0';
  return (str);
}

void	display_cmd(t_all *g_all, t_sel *sel, char *final, char opt)
{
  char	*place;

  myclear(g_all);
  display(g_all);
  my_putchar('\n', sel->ttyfd);
  place = tgoto(tgetstr("cm", NULL), 0, sel->height);
  my_putstr(place, sel->ttyfd);
  load_ent(sel, "ue");
  load_ent(sel, "me");
  if (opt == 0)
    my_putstr("Searching something matching with: ", sel->ttyfd);
  else
    my_putstr("Searching the file: ", sel->ttyfd);
 my_putstr(final, sel->ttyfd);
}

void	search_matching(t_sel *sel, char *final)
{
  int	i;

  i = 0;
  sel->selected = 0;
  while (i < sel->max_elem)
    {
      if (sel->state[i] != 4)
	{
	  if (my_match(sel->arg[i], final) == 1)
	    {
	      if (sel->state[i] < 2)
		{
		  sel->state[i] += 2;
		  sel->selected += 1;
		}
	    }
	  else if (sel->state[i] >= 2)
	      sel->state[i] -= 2;
	}
      i += 1;
    }
}

void	select_matching(t_all *g_all, t_sel *sel)
{
  char	buf[10];
  char	*final;
  int	let;

  init_tab(buf, 10);
  if ((final = malloc(1)) == NULL)
    error(1);
  final[0] = '\0';
  display_cmd(g_all, sel, final, 0);
  while (!ENTER && !ESC)
    {
      display_cmd(g_all, sel, final, 0);
      init_tab(buf, 10);
      if ((let = read(0, buf, 9)) == -1)
	error(2);
      if (!ENTER && !ESC)
	{
	  if (BSPACE || DEL)
	    final = delete_let(final);
	  else if ((final = my_copie(final, buf, let)) == NULL)
	    error(1);
	  search_matching(sel, final);
	}
    }
  free(final);
}

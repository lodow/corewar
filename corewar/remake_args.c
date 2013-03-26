/*
** remake_args.c for remake in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Mar 21 11:40:33 2013 luc sinet
** Last update Thu Mar 21 14:30:19 2013 luc sinet
*/

#include <stdlib.h>
#include "pre_pars.h"
#include "../misc/str_func.h"

char	*renew_folder(char *folder)
{
  char	*new;

  if (folder[my_strlen(folder) - 1] == '/')
    return (my_strdup(folder));
  if ((new = malloc(my_strlen(folder + 2))) == NULL)
    return (NULL);
  new[0] = '\0';
  my_strcat(new, folder);
  my_strcat(new, "/");
  return (new);
}

int	tab_size(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

char	**copy_old(char **args, char *folder, t_sel *spt, int *i)
{
  int	x;

  x = 0;
  while (spt->new_args[x])
    x++;
  while (args[*i] && my_strcmp(args[*i], folder) != 0)
    if ((spt->new_args[x++] = my_strdup(args[(*i)++])) == NULL)
      return (NULL);
  if (args[*i])
    (*i)++;
  spt->new_args[x] = '\0';
  return (spt->new_args);
}

char	**copy_new(char **args, t_sel *spt)
{
  int	x;
  int	i;

  i = 0;
  x = 0;
  while (spt->new_args[x])
    x++;
  while (spt->sel_tab[i])
    if ((spt->new_args[x++] = my_strdup(spt->sel_tab[i++])) == NULL)
      return (NULL);
  spt->new_args[x - 1][my_strlen(spt->new_args[x - 1]) - 1] = '\0';
  spt->new_args[x] = '\0';
  return (spt->new_args);
}

char	**change_args(char **args, char *folder, t_sel *spt)
{
  int	i;

  i = 0;
  if ((spt->sel_tab = my_str_to_wordtab(spt->sel_res, ' ', '\t')) == NULL)
    return (NULL);
  if ((spt->new_args = malloc(sizeof(char *)
			      * (tab_size(args)
				 + tab_size(spt->sel_tab) + 1))) == NULL);
  spt->new_args[0] = '\0';
  if (copy_old(args, folder, spt, &i) == NULL ||
      copy_new(args, spt) == NULL ||
      copy_old(args, folder, spt, &i) == NULL)
    return (NULL);
  return (spt->new_args);
}

#include <stdlib.h>
#include "pre_pars.h"
#include "../misc/str_func.h"

char	**copy_tab(char **tab)
{
  char	**new_tab;
  int	i;

  i = 0;
  while (tab[i])
    i++;
  if ((new_tab = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i])
    {
      if ((new_tab[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  new_tab[i] = '\0';
  return (new_tab);
}

int		check_if_folder(char *file)
{
  struct stat	s;

  if (stat(file, &s) == -1)
    return (-1);
  else if ((s.st_mode & MASK) == ISDIR)
    return (1);
  return (0);
}

char	**pre_pars(char **args, char **env)
{
  char	**nargs;
  int	i;

  i = 0;
  if ((nargs = copy_tab(args)) == NULL)
    return (NULL);
  while (nargs[i])
    {
      if (check_if_folder(nargs[i]) == 1)
	if ((nargs = launch_select(nargs, env, nargs[i])) == NULL)
	  return (NULL);
      i++;
    }
  return (nargs);
}

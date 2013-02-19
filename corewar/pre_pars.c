/*
** pre_pars.c for pre_pars in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sun Feb  3 12:44:12 2013 luc sinet
** Last update Sun Feb  3 13:57:22 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "include.h"

int	test_opt(char **args, int pos)
{
  int	i;
  char	*tab[4];

  tab[0] = "-dump";
  tab[1] = "-n";
  tab[2] = "-a";
  tab[3] = "-unlimited";
  i = 0;
  while (i < 4 && my_strcmp(args[pos], tab[i]) != 0)
    i += 1;
  if (i == 4)
    return (-1);
  return (1);
}

int	get_new_args(char **args, char **env, int pos, int nb_args)
{
  pid_t	pid;
  char	*cmd[3];

  cmd[0] = "my_select";
  cmd[1] = args[pos];
  cmd[2] = (char *)0;
  if ((pid = fork()) == -1)
    {
      my_putstr("Fork error\n", 2, -1);
      return (nb_args);
    }
  if (pid == 0)
    {
      if (execve("my_select", cmd, env) == -1)
        {
          my_putstr("Failed to execute my_select\n", 2, -1);
          return (nb_args);
        }
    }
  else
    wait(NULL);
  return (nb_args);
}

int		test_folder(char **args, char **env, int pos, int nb_args)
{
  struct stat	s;

  if (stat(args[pos], &s) == -1)
    {
      my_putstr("stat function failed\n", 2, -1);
      return (nb_args);
    }
  if (s.st_mode & 0040000)
    return (get_new_args(args, env, pos, nb_args));
  return (nb_args);
}

int	pre_pars(char **args, char **env, int nb_args)
{
  int	i;

  i = 0;
  while (i < nb_args)
    {
      if (test_opt(args, i) == -1)
        nb_args = test_folder(args, env, i, nb_args);
      i += 1;
    }
  return (nb_args);
}

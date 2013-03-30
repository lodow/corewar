/*
** main.c for main in /home/sinet_l//myselect-2017-sinet_l
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 15 12:17:05 2013 luc sinet
** Last update Sun Jan 20 15:11:40 2013 luc sinet
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "select.h"

t_all	*g_all;

void	error(int opt)
{
  if (opt == 0)
    my_putstr("Error while using the function malloc\n", 2);
  else if (opt == 1)
    my_putstr("Error while geting/seting the terminal atributes\n", 2);
  else if (opt == 2)
    my_putstr("Read error\n", 2);
  exit(0);
}

void	mfree()
{
  int	i;
  char	*str;

  i = 0;
  load_ent(g_all->sel, "ue");
  load_ent(g_all->sel, "me");
  load_ent(g_all->sel, "ve");
  if (tcsetattr(g_all->sel->ttyfd, TCSANOW, &(g_all->prev)) == -1)
    error(1);
  close(g_all->sel->ttyfd);
  while (g_all->sel->arg[i])
    free(g_all->sel->arg[i++]);
  free(g_all->sel->arg);
  free(g_all->sel->size);
  free(g_all->sel->state);
  free(g_all->sel);
  free(g_all->dis);
  free(g_all);
  exit(0);
}

void	fill_args(t_sel *sel, char **av, int size)
{
  int	i;

  i = 0;
  if (!((sel->arg = malloc(sizeof(char*) * size)) != NULL &&
	(sel->state = malloc(sizeof(char) * size)) != NULL &&
	(sel->size = malloc(sizeof(int) * size)) != NULL))
    error(0);
  while (av[i + 1])
    {
      if ((sel->arg[i] = my_strdup(av[i + 1])) == NULL)
	error(0);
      sel->size[i] = my_strlen(sel->arg[i]);
      if (i == 0)
	sel->state[i] = 1;
      else
	sel->state[i] = 0;
      i++;
    }
  sel->arg[i] = '\0';
  sel->nb_elem = size - 1;
  sel->max_elem = size - 1;
  sel->pos = 0;
  sel->selected = 0;
}

int	check_args(int ac, char **env)
{
  int	i;

  i = 0;
  if (ac < 2)
    {
      my_putstr("You need to enter at least one argument\n", 1);
      return (0);
    }
  else if (env == NULL)
    {
      my_putstr("Thanks to specifie an environement\n", 1);
      return (0);
    }
  while (env[i] && my_strncmp(env[i], "TERM=", 5) != 0)
    i++;
  if (!env[i])
    {
      my_putstr("Please, set TERM to use the program\n", 1);
      return (0);
    }
  return (1);
}

int	main(int ac, char **av, char **env)
{
  t_sel	*sel;
  t_dis	*dis;

  if ((sel = malloc(sizeof(*sel))) == NULL ||
      (dis = malloc(sizeof(*dis))) == NULL ||
      (g_all = malloc(sizeof(*g_all))) == NULL)
    error(0);
  g_all->dis = dis;
  g_all->sel = sel;
  if ((sel->ttyfd = open("/dev/tty", O_WRONLY)) == -1)
    {
      my_putstr("Can't find tty output\n", 2);
      return (0);
    }
  if (!check_args(ac, env) || fgetent(env) == -1)
    return (0);
  fill_args(sel, av, ac);
  change_mod(g_all, sel);
  cmd(g_all, sel, dis);
  my_putchar('\n', sel->ttyfd);
  mfree();
  return (0);
}

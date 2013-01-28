/*
** check_options.c for check_options in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Jan 24 16:55:02 2013 luc sinet
** Last update Mon Jan 28 18:14:55 2013 luc sinet
*/

#include "include.h"

int	check_dump(char **av, t_arg *parg)
{
  if (parg->dump != -1 || parg->pos != 0 || parg->nb_arg == 1)
    return (-1);
  if (is_a_num(av[parg->pos + 1]) == -1)
    return (-1);
  parg->dump_val = my_getnbr(av[parg->pos + 1]);
  parg->pos += 1;
  parg->dump = 1;
  return (0);
}

int	check_exist(char **av, t_arg *parg, int num)
{
  int	i;

  i = 0;
  while (i < parg->nb_arg)
    {
      if (parg->num_used[i] == num)
	{
	  my_putstr("prog number ", 2, -1);
	  my_putstr(av[parg->pos + 1], 2 , -1);
	  my_putstr(" already used\n", 2, -1);
	  return (-1);
	}
      i += 1;
    }
  return (0);
}

int	check_numproc(char **av, t_arg *parg)
{
  if (parg->num != -1 || (parg->pos + 1) >= parg->nb_arg)
    return (-1);
  if (is_a_num(av[parg->pos + 1]) == 1)
    {
      if (my_getnbr(av[parg->pos + 1]) < 0)
	{
	  my_putstr("Please enter a positive value for the -n option\n", 2, -1);
	  return (-2);
	}
      else if (check_exist(av, parg, my_getnbr(av[parg->pos + 1])) == -1)
	return (-2);
      else
	{
	  parg->num_used[parg->num_pos] = my_getnbr(av[parg->pos + 1]);
	  parg->pos += 1;
	}
    }
  else
    return (0);
  parg->num_pos += 1;
  parg->num = 1;
  return (0);
}

int	check_addr(char **av, t_arg *parg)
{
  if (parg->addr != -1 || (parg->pos + 1) >= parg->nb_arg)
    return (-1);
  if (is_a_num(av[parg->pos + 1]) == 1)
    {
      parg->addr_used[parg->addr_pos] = my_getnbr(av[parg->pos + 1]);
      parg->addr_pos += 1;
      parg->pos += 1;
    }
  parg->addr = 1;
  return (0);
}

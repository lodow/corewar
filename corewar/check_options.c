#include "include.h"

int	check_dump(char **av, t_arg *parg)
{
  if (parg->vm->cycle_to_dump != -1 || parg->pos + 1 >= parg->nb_arg ||
      parg->opt[1] != -1 || parg->opt[2] != -1)
    return (-1);
  if (is_a_num(av[parg->pos + 1]) == -1)
    return (-1);
  parg->vm->cycle_to_dump = my_getnbr(av[parg->pos + 1]);
  parg->pos += 1;
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
  if (parg->opt[1] != -1 || (parg->pos + 1) >= parg->nb_arg)
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
  parg->opt[1] = 1;
  return (0);
}

int	check_addr(char **av, t_arg *parg)
{
  int	val;

  if (parg->opt[2] != -1 || (parg->pos + 1) >= parg->nb_arg)
    return (-1);
  if (is_a_num(av[parg->pos + 1]) == 1)
    {
      if ((val = my_getnbr(av[parg->pos + 1])) < 0)
	{
	  my_putstr("Please enter a positive value for the -a option\n", 2, -1);
	  return (-2);
	}
      parg->addr_used[parg->addr_pos] = val;
      parg->addr_pos += 1;
      parg->pos += 1;
    }
  parg->opt[2] = 1;
  return (0);
}

int	check_adds(char **av, t_arg *parg)
{
  if (my_strcmp("-unlimited", av[parg->pos]) == 0)
    {
      if (parg->opt[0] != -1)
	  return (-1);
      parg->opt[0] = 1;
    }
  else if (my_strcmp("-d", av[parg->pos]) == 0)
    {
      if (parg->opt[3] != -1)
	return (-1);
      parg->opt[3] = 1;
    }
  return (0);
}

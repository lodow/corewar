/*
** pars_args.c for pars_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 20:47:09 2013 luc sinet
** Last update Sun Jan 27 15:52:37 2013 luc sinet
*/

#include "include.h"
#include "../misc/op.h"

int	dump_opt(char **av, t_arg *parg)
{
  parg->dump_val = my_getnbr(av[parg->pos + 1]);
  return (0);
}

int	prog_num_opt(char **av, t_arg *parg)
{
  if (is_a_num(av[parg->pos + 1]) == 1)
    {
      parg->num_val = my_getnbr(av[parg->pos + 1]);
      parg->pos += 1;
      parg->num_used[parg->num_pos] = parg->num_val;
      parg->num_pos += 1;
    }
  return (0);
}

int	addr_opt(char **av, t_arg *parg)
{
  if (is_a_num(av[parg->pos + 1]) == 1)
    {
      parg->addr_val = my_getnbr(av[parg->pos + 1]) % MEM_SIZE;
      parg->pos += 1;
    }
  return (0);
}

int	pars_opt(char **av, t_arg *parg)
{
  int	i;
  char	*opt_list[3];

  i = 0;
  opt_list[0] = "dump";
  opt_list[1] = "-n";
  opt_list[2] = "-a";
  while (i < 3 && my_strcmp(opt_list[i], av[parg->pos]) != 0)
    i++;
  if (i == 3)
    return (-1);
  if (i == 0)
    return (dump_opt(av, parg));
  else if (i == 1)
    return (prog_num_opt(av, parg));
  else
    return (addr_opt(av, parg));
}

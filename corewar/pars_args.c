/*
** pars_args.c for pars_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 20:47:09 2013 luc sinet
** Last update Fri Feb  1 15:25:19 2013 luc sinet
*/

#include "include.h"
#include "../misc/op.h"

int	dump_opt(char **av, t_arg *parg)
{
  parg->vm->cycle_to_dump = my_getnbr(av[parg->pos + 1]);
  parg->pos += 1;
  return (0);
}

int	prog_num_opt(char **av, t_arg *parg)
{
  if (is_a_num(av[parg->pos + 1]) == 1)
    {
      parg->num_used[parg->num_pos] = my_getnbr(av[parg->pos + 1]);
      parg->num_pos += 1;
      parg->opt[1] = 1;
      parg->pos += 1;
    }
  return (0);
}

int	addr_opt(char **av, t_arg *parg)
{
  if (is_a_num(av[parg->pos + 1]) == 1)
    {
      parg->addr_used[parg->addr_pos] =
	my_getnbr(av[parg->pos + 1]) % MEM_SIZE;
      parg->addr_pos += 1;
      parg->opt[2] = 1;
      parg->pos += 1;
    }
  return (0);
}

int	adds_opt(char **av, t_arg *parg)
{
  if (my_strcmp("-unlimited", av[parg->pos]) == 0)
    {
      parg->opt[0] = 1;
      parg->vm->flag = 1;
    }
  else
    return (0);
  return (0);
}

int	pars_opt(char **av, t_arg *parg)
{
  int	i;
  char	*opt_list[4];
  int	(*opt[5])(char **av, t_arg *parg);

  i = 0;
  opt[0] = &dump_opt;
  opt[1] = &prog_num_opt;
  opt[2] = &addr_opt;
  opt[3] = &adds_opt;
  opt[4] = &opt_error;
  opt_list[0] = "-dump";
  opt_list[1] = "-n";
  opt_list[2] = "-a";
  opt_list[3] = "-unlimited";
  while (i < 4 && my_strcmp(opt_list[i], av[parg->pos]) != 0)
    i++;
  return (opt[i](av, parg));
}

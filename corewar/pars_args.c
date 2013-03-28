/*
** pars_args.c for pars_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 20:47:09 2013 luc sinet
** Last update Tue Mar 26 15:53:20 2013 luc sinet
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
      parg->addr_used[parg->addr_pos]
        = my_getnbr(av[parg->pos + 1]) % MEM_SIZE;
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
      SETFLAG(parg->vm->flag, FLAGPOS(UNLIMITEDOPT));
      parg->opt[0] = 1;
    }
  else if (my_strcmp("-d", av[parg->pos]) == 0)
    {
      parg->opt[3] = 1;
      SETFLAG(parg->vm->flag, FLAGPOS(DEBUGOPT));
    }
  return (0);
}

int	pars_opt(char **av, t_arg *parg)
{
  int	i;
  char	*opt_list[5];
  int	(*opt[6])(char **av, t_arg * parg);

  i = 0;
  opt[0] = &dump_opt;
  opt[1] = &prog_num_opt;
  opt[2] = &addr_opt;
  opt[3] = &adds_opt;
  opt[4] = &adds_opt;
  opt[5] = &opt_error;
  opt_list[0] = "-dump";
  opt_list[1] = "-n";
  opt_list[2] = "-a";
  opt_list[3] = "-unlimited";
  opt_list[4] = "-d";
  while (i < 5 && my_strcmp(opt_list[i], av[parg->pos]) != 0)
    i++;
  return (opt[i](av, parg));
}

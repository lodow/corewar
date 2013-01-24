/*
** pars_args.c for pars_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Wed Jan 23 20:47:09 2013 luc sinet
** Last update Thu Jan 24 13:30:08 2013 luc sinet
*/

#include "include.h"

void	dump_opt(int nb_cycle)
{

}

void	prog_num_opt(int nb)
{

}

void	load_addr_opt(int addr)
{

}

int	pars_opt(char **av, int *pos, int max)
{
  int	i;
  char	*opt_list[3];

  i = 0;
  opt_list[0] = "dump";
  opt_list[1] = "-n";
  opt_list[2] = "-a";
  while (i < 3 && my_strcmp(opt_list[i], av[*pos]) != 0)
    i++;
  if (i == 0)
    dump_opt(my_getnbr(av[*pos + 1]));
  else if (i == 1)
    prog_num_opt(my_getnbr(av[*pos + 1]));
  else
    {
      if (*pos + 1 == max)
	load_addr_opt(-1);
      else
	load_addr_opt(my_getnbr(av[*pos + 1]));
    }
  return (0);
}

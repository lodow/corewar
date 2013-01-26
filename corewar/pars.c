/*
** pars for pars in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 22 15:41:27 2013 luc sinet
** Last update Sat Jan 26 13:41:25 2013 luc sinet
*/

#include "include.h"

void	error_msg(int type)
{
  if (type == 0)
    my_putstr("Error, please verifie your arguments\n"
              "./corewar [-dump nbr_cycle][[-n prog_number]"
              "[-a load_address ] prog_name ...]\n", 2, -1);
  else if (type == 1)
    my_putstr("Error while loading the champ file\n", 2, -1);
  else if (type == 2)
    my_putstr("Can’t perform malloc", 2, -1);
}

int	check_args(char **av, t_arg *parg)
{
  int	error;

  while (parg->pos < parg->nb_arg)
    {
      if ((error = opt_compare(av, parg)) == -2)
	return (-1);
      else if (error < 0 && (error = check_champ(av[parg->pos], parg)) < 0)
        {
	  if (error == -1)
	    error_msg(0);
	  return (-1);
        }
      parg->pos += 1;
    }
  if (parg->nb_champ == 0 || parg->num == 1 || parg->addr == 1)
    {
      error_msg(0);
      return (-1);
    }
  return (0);
}

int	pars_args(char **av, t_arg *parg)
{

}

t_arg	*init_arg(int ac)
{
  t_arg	*parg;

  if ((parg = malloc(sizeof(*parg))) == NULL ||
      (parg->num_used = malloc(sizeof(int) * (ac / 2))) == NULL)
    {
      error_msg(2);
      return (NULL);
    }
  my_memset(parg->num_used, ac / 2, -1);
  parg->pos = 0;
  parg->dump = 0;
  parg->num = 0;
  parg->addr = 0;
  parg->nb_champ = 0;
  parg->num_pos = 0;
  parg->num_val = -1;
  parg->nb_arg = ac;
  return (parg);
}

int	pars(char **av, int ac)
{
  t_arg	*parg;

  if ((parg = init_arg(ac)) == NULL || check_args(av, parg) == -1)
    return (-1);
  free(parg->num_used);
  free(parg);
  if ((parg = init_arg(ac)) == NULL || pars_args(av, parg) == -1)
    return (-1);
  return (0);
}


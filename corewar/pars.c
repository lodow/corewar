/*
** pars for pars in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 22 15:41:27 2013 luc sinet
** Last update Wed Jan 30 15:46:30 2013 luc sinet
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
    my_putstr("Can't perform malloc\n", 2, -1);
  else if (type == 3)
    my_putstr("Please enter at least one argument\n", 2, -1);
}

int	check_args(char **av, t_arg *parg)
{
  int	error;

  parg->nb_champ = 0;
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
      if (parg->nb_champ == 0)
	error_msg(3);
      else
	error_msg(0);
      return (-1);
    }
  return (0);
}

int	pars_args(char **av, t_arg *parg)
{
  while (parg->pos < parg->nb_arg)
    {
      if (pars_opt(av, parg) < 0 && pars_champ(av[parg->pos], parg) < 0)
	return (-1);
      parg->pos += 1;
    }
  return (0);
}

t_arg	*init_arg(t_arg *parg, int ac, t_vm *vm)
{
  if ((parg->num_used = malloc(sizeof(int) * ac)) == NULL ||
      (parg->addr_used = malloc(sizeof(int) * ac)) == NULL)
    {
      error_msg(2);
      return (NULL);
    }
  parg->num_used = my_memseti(parg->num_used, ac, -1);
  parg->addr_used = my_memseti(parg->addr_used, ac, -1);
  parg->pos = 0;
  parg->added_champ = 0;
  parg->num = -1;
  parg->addr = -1;
  parg->num_pos = 0;
  parg->addr_pos = 0;
  parg->nb_arg = ac;
  parg->vm = vm;
  return (parg);
}

int	pars(char **av, int ac, t_vm *vm)
{
  t_arg	*parg;

  if ((parg = malloc(sizeof(*parg))) == NULL ||
      (parg = init_arg(parg, ac, vm)) == NULL || check_args(av, parg) == -1)
      {
	if (parg == NULL)
	  error_msg(2);
	return (-1);
      }
  free(parg->num_used);
  free(parg->addr_used);
  if ((parg = init_arg(parg, ac, vm)) == NULL || pars_args(av, parg) == -1)
    {
      if (parg == NULL)
	error_msg(2);
      return (-1);
    }
  free(parg->num_used);
  free(parg->addr_used);
  free(parg);
  return (0);
}


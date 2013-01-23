/*
** pars_args.c for pars_args in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Tue Jan 22 15:41:27 2013 luc sinet
** Last update Wed Jan 23 17:01:59 2013 luc sinet
*/

#include "include.h"

void	error_msg(int type)
{
  if (type == 0)
    my_putstr("Error, please verifie your arguments\n"
              "./corewar [-dump nbr_cycle][[-n prog_number]"
              "[-a load_address ] prog_name]", 1, -1);
}

int	check_args(char **av, int nb_arg)
{
  int	i;
  int	error;

  while (i < nb_arg)
    {
      if (!(error = check_opt(av, av[i], &i, nb_arg)))
        {
          if (error == -2 || !check_champ(av[i]))
            {
              error_msg(0);
              return (-1);
            }
        }
      i += 1;
    }
  return (0);
}

int	pars(char **av, int ac)
{
  if (ac == 1 || check_args(av, ac - 1) == -1)
    return (-1);

}

/*
** pars_champ.c for pars_champ in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Jan 24 13:30:51 2013 luc sinet
** Last update Mon Jan 28 14:10:33 2013 luc sinet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include.h"

/*
** This function will set the process number
** (if no arguments were entered)
** to the next not already chosen number.
*/
void	set_numval(t_arg *parg)
{
  int	i;
  char	hit;

  hit = 1;
  if (parg->num_used[0] == -1)
    {
      parg->num_pos += 1;
      parg->num_used[0] += 1;
      parg->num_val = parg->num_used[0];
      return ;
    }
  parg->num_val = parg->num_used[parg->num_pos - 1];
  while (hit == 1)
    {
      i = 0;
      hit = 0;
      parg->num_val += 1;
      while (parg->num_used[i] != parg->num_val && parg->num_used[i] != -1)
        i += 1;
      if (parg->num_used[i] == parg->num_val)
        hit = 1;
    }
  parg->num_used[(parg->num_pos)++] = parg->num_val;
}

void	set_addrval(t_arg *parg)
{

}

void	check_value(t_arg *parg)
{
  if (parg->num == -1)
    set_numval(parg);
  if (parg->addr == -1)
    set_addrval(parg);
}

void	preload_champ(t_vm *vm, t_arg *parg)
{
  int	i;

  i = 0;
  while (vm->champs[i])
    {
      my_add_to_list(&(vm->process_list),
                     up_champ_t_mem(vm, vm->champs[i], parg->addr_val));
      i += 1;
    }
}

int	pars_champ(char *name, t_arg *parg)
{
  int	fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (-1);
  check_value(parg);
  if ((parg->vm->champs = add_champ_t_tab
	 (parg->vm->champs, load_champ(fd, parg->num_val))) == NULL)
    return (-1);
  parg->num = -1;
  parg->addr = -1;
  parg->added_champ += 1;
  if (parg->added_champ == parg->nb_champ)
    preload_champ(parg->vm, parg);
  return (0);
}

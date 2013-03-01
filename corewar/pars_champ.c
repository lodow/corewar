/*
** pars_champ.c for pars_champ in /home/sinet_l//corewar/corewar
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Jan 24 13:30:51 2013 luc sinet
** Last update Fri Feb  1 15:58:10 2013 luc sinet
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
  int	num_val;
  char	hit;

  hit = 1;
  if (parg->num_used[0] == -1)
  {
    parg->num_used[0] = 1;
    parg->num_pos = 1;
    return ;
  }
  num_val = parg->num_used[parg->num_pos - 1];
  while (hit == 1)
  {
    i = 0;
    hit = 0;
    num_val += 1;
    while (parg->num_used[i] != num_val && i < parg->nb_arg - 1)
      i += 1;
    if (parg->num_used[i] == num_val)
      hit = 1;
  }
  parg->num_used[parg->num_pos] = num_val;
  parg->num_pos += 1;
}

void	set_addrval(t_arg *parg)
{
  int	i;
  int	tsize;
  int	inter;
  int	addr;

  i = 0;
  tsize = 0;
  addr = 0;
  while (i < parg->nb_champ)
    tsize += parg->vm->champs[i++]->header.prog_size;
  inter = (MEM_SIZE - tsize) / parg->nb_champ;
  i = 0;
  while (i < parg->nb_champ)
  {
    if (parg->addr_used[i] == -1)
      if (parg->added_champ != 0)
      {
        parg->addr_used[parg->addr_pos] = addr;
        addr += (inter + parg->vm->champs[i]->header.prog_size);
        parg->addr_pos += 1;
      }
    i += 1;
  }
}

void	check_value(t_arg *parg, char opt)
{
  if (opt == 1)
  {
    if (parg->opt[1] == -1)
      set_numval(parg);
  }
  else
  {
    if (parg->opt[2] == -1)
      set_addrval(parg);
  }
}

int	preload_champ(t_vm *vm, t_arg *parg)
{
  int	i;

  i = 0;
  check_value(parg, 2);
  while (vm->champs[i] != NULL)
  {
    my_add_to_list(&(vm->process_list),
                   up_champ_t_mem(vm, vm->champs[i], parg->addr_used[i]));
    i += 1;
  }
  if (!vm->champs[0])
  {
    my_putstr("The vm can't start: There is not"
              " at least one valid .cor file\n", 2, -1);
    return (-1);
  }
  return (1);
}

int		pars_champ(char *name, t_arg *parg)
{
  int		fd;
  t_champ	*champ;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (-1);
  check_value(parg, 1);
  if ((champ = load_champ(fd, parg->num_used[parg->added_champ], name)) ==
      NULL ||
      (parg->vm->champs = add_champ_t_tab(parg->vm->champs, champ)) == NULL)
    return (-1);
  parg->opt[1] = -1;
  parg->opt[2] = -1;
  parg->added_champ += 1;
  if (parg->added_champ == parg->nb_champ)
    if (preload_champ(parg->vm, parg) == -1)
      return (-1);
  return (0);
}

/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

int		exe_process(void *ptrproc, void *ptrvm)
{
  t_process	*proc;
  t_vm		*vmstat;
  char		instr;

  proc = ptrproc;
  vmstat = ptrvm;
  if (proc->nb_cycle_t_next <= 1)
    {
      instr = vmstat->mem[MOD_MEM(proc->pc)] - 1;
      if ((instr >= 0) && (instr <= 15))
        {
          proc->nb_cycle_t_next = vmstat->instr_nb_cycle[(int)instr];
          proc->pc = MOD_MEM(vmstat->f[(int)instr](proc, vmstat) + proc->pc);
        }
      else
        proc->pc = MOD_MEM(proc->pc + 1);
    }
  else
    proc->nb_cycle_t_next--;
  return (0);
}

int		delete_process(void *ptr)
{
  t_process	*proc;

  proc = ptr;
  free(proc);
  return (0);
}

t_process	*create_new_process(t_process *src, int pc)
{
  t_process	*newp;
  int		i;
  int		j;

  i = 0;
  if (((newp = malloc(1 * sizeof(t_process))) == NULL) || (src == NULL))
    return (NULL);
  newp->pc = pc;
  newp->carry = src->carry;
  newp->nb_cycle_t_next = 0;
  while (i < REG_NUMBER)
    {
      j = 0;
      while (j < REG_SIZE)
        {
          newp->reg[i][j] = src->reg[i][j];
          j++;
        }
      i++;
    }
  return (newp);
}

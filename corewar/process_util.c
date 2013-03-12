/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 19:26:33 2013 luc sinet
*/

#include	"include.h"

int		exe_process(void *ptrproc, void *ptrvm)
{
  t_process	*proc;
  t_vm		*vmstat;
  int		instrlen;

  proc = ptrproc;
  vmstat = ptrvm;
  if (proc->nb_cycle_t_next <= 1)
    {
      if ((proc->instr >= 0) && (proc->instr <= 15))
        {
          instrlen = vmstat->f[(int)proc->instr](proc, vmstat);
          proc->pc = MOD_MEM(instrlen + proc->pc);
        }
      else
        {
          proc->pc = MOD_MEM(proc->pc + 1);
          printf("Operation pourrie\n");
        }
      proc->instr = GET_INSTR;
      if ((proc->instr >= 0) && (proc->instr <= 15))
        proc->nb_cycle_t_next = vmstat->instr_nb_cycle[(int)proc->instr];
      fill_param_struct(vmstat, proc);
    }
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

t_process	*create_new_process(t_vm *vmstat, t_process *src, int pc)
{
  t_process	*proc;
  int		i;

  i = 0;
  if (((proc = malloc(1 * sizeof(t_process))) == NULL) || (src == NULL))
    return (NULL);
  proc->pc = pc;
  proc->associated_champ = src->associated_champ;
  proc->carry = src->carry;
  proc->nb_cycle_t_next = 0;
  while (i < REG_NUMBER)
    {
      proc->reg[i] = src->reg[i];
      i++;
    }
  proc->instr = GET_INSTR;
  proc->nb_cycle_t_next = CHECK_INST_CYCLE(proc->instr);
  fill_param_struct(vmstat, proc);
  return (proc);
}

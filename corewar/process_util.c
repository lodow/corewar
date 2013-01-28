/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Jan 26 17:00:24 2013 luc sinet
*/

#include	"include.h"

int		exe_process(void *ptrproc, void *ptrvm)
{
  t_process	*proc;
  t_vm		*vmstat;
  int		instrlen;
  char		instr;

  proc = ptrproc;
  vmstat = ptrvm;
  if (proc->nb_cycle_t_next <= 1)
    {
      instr = GET_INSTR;
      if ((instr >= 0) && (instr <= 15))
        {
/*        dump_memory(proc->params_next_instr.params, MAX_ARGS_NUMBER * 4);*/
          instrlen = vmstat->f[(int)instr](proc, vmstat);
          proc->pc = MOD_MEM(instrlen + proc->pc);
          instr = GET_INSTR;
          if ((instr >= 0) && (instr <= 15))
            proc->nb_cycle_t_next = vmstat->instr_nb_cycle[(int)instr];
          fill_param_struct(vmstat, proc);
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

t_process	*create_new_process(t_vm *vmstat, t_process *src, int pc)
{
  t_process	*proc;
  int		i;
  int		j;

  i = 0;
  if (((proc = malloc(1 * sizeof(t_process))) == NULL) || (src == NULL))
    return (NULL);
  proc->pc = pc;
  proc->associated_champ = src->associated_champ;
  proc->carry = src->carry;
  proc->nb_cycle_t_next = 0;
  while (i < REG_NUMBER)
    {
      j = 0;
      while (j < REG_SIZE)
        {
          proc->reg[i][j] = src->reg[i][j];
          j++;
        }
      i++;
    }
  proc->nb_cycle_t_next = vmstat->instr_nb_cycle[GET_INSTR];
  fill_param_struct(vmstat, proc);
  return (proc);
}

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

void	fill_param_struct(t_vm *vm, t_process *proc)
{
  t_params	*params;
  int		i;

  i = 0;
  params = &(proc->params_next_instr);
  params->type = vm->mem[MOD_MEM(proc->pc + 1)];
  while (i < (MAX_ARGS_NUMBER * 4))
    {
      params->params[i] = vm->mem[MOD_MEM(proc->pc + 2)];
      i++;
    }
}

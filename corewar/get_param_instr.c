#include	"include.h"

void	fill_param_struct(t_vm *vm, t_process *proc)
{
  t_params	*params;
  int		i;

  i = 0;
  params = &(proc->params_next_instr);
  while (i < (MAX_ARGS_NUMBER * 4 + 1))
    {
      params->params[i] = vm->mem[MOD_MEM(proc->pc + 1 + i)];
      i++;
    }
}

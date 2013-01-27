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

void	init_instr_params(t_params *params)
{
  params->param1 = NULL;
  params->param2 = NULL;
  params->param3 = NULL;
  params->param4 = NULL;
}

void	delete_instr_params(t_params *params)
{
  params->type = 0x00;
  free(params->param1);
  free(params->param2);
  free(params->param3);
  free(params->param4);
  init_instr_params(params);
}

void	fill_param_struct(t_vm *vm, t_process *proc)
{
  t_params	*params;
  char		tmp;
  char		instr;
  void		(*(f[3]))(t_vm * vm, int offset, char **res);

  params = &(proc->params_next_instr);
  instr = VM_MEM(proc->pc);
  if ((instr >= 1) && (instr <= 16) && (instr != 0x0c) && (instr != 0x01)
      && (instr != 0x0f) && (instr != 0x09))
    {
      params->type = VM_MEM(proc->pc + 1);
      if ((tmp = GET_TYPE_PARAMX(params->type, 0)) != 0)
        f[tmp - 1](vm, proc->pc + 2, &(params->param1));
      if ((tmp = GET_TYPE_PARAMX(params->type, 1)) != 0)
        f[tmp - 1](vm, proc->pc + 2 + NBBP(tmp, 1), &(params->param1));
      if ((tmp = GET_TYPE_PARAMX(params->type, 2)) != 0)
        f[tmp - 1](vm, proc->pc + 2 + NBBP(tmp, 2), &(params->param1));
      if ((tmp = GET_TYPE_PARAMX(params->type, 3)) != 0)
        f[tmp - 1](vm, proc->pc + 2 + NBBP(tmp, 3), &(params->param1));
    }
}

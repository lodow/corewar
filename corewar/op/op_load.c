/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_load(t_process *proc, t_vm *vm)
{
  char	*src;
  int	regp2;

  src = get_paramx(vm, proc, VM_MEM(proc->pc + 2), 1);
  regp2 = *((int*)src);
  free(src);
  src = NULL;
  if (VM_MEM(proc->pc + 1) == 3)
    src = resolve_ind_value(vm, proc->pc + 2, proc->pc, 1);
  else
    src = get_paramx(vm, proc, VM_MEM(proc->pc + 2), 0);
  cpy_t_registre(src, &(proc->reg[regp2]));
  free(src);
  return (NBPBYTE(VM_MEM(proc->pc + 2), MAX_ARGS_NUMBER) + 2);
}

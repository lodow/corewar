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
int	op_st(t_process *proc, t_vm *vm)
{
  char	*src;
  int	regp1;

  if ((src = get_paramx(vm, proc, VM_MEM(proc->pc + 2), 0)) != NULL)
    regp1 = *((int*)src);
  if (is_byte_zero(src, REG_SIZE) && (src != NULL))
    proc->carry = 1;
  free(src);
  src = NULL;
  if (GET_TYPE_PARAMX(VM_MEM(proc->pc + 1), 1) == 3)

    else
      src = get_paramx(vm, proc, VM_MEM(proc->pc + 2), 0);
  cpy_t_registre(src, &(proc->reg[regp2]));
  printf("%ld executed instruction st %d at pc %d\n", proc, (int)(proc->reg[regp2]), proc->pc);
  free(src);
  return (NBPBYTE(VM_MEM(proc->pc + 2), MAX_ARGS_NUMBER) + 2);
}

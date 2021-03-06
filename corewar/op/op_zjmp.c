#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction or the new adresse to jump to !
*/

void	debug_zjump(t_process *proc, short off_addr)
{
  my_putstr(proc->associated_champ->header.prog_name, 1, -1);
  my_putstr("\t", 1, 1);
  my_putstr(" zjump (", 1, -1);
  my_put_nbr(off_addr % IDX_MOD, 1);
  my_putstr(") carry = ", 1, -1);
  my_put_nbr(proc->carry, 1);
  my_putstr("\n", 1 , -1);
}

int	op_zjmp(t_process *proc, t_vm *vm)
{
  int	i;
  int	j;
  short	off_adrr;
  char	*tmp;

  i = 0;
  tmp = ((char*)(&off_adrr));
  j = IND_SIZE - 1;
  while (i < IND_SIZE)
    {
      tmp[i] = VM_MEM(proc->pc + 1 + j);
      j--;
      i++;
    }
  DEBUGCALL(ISDEBUGMODE, debug_zjump(proc, off_adrr));
  if (proc->carry == 1)
    return (off_adrr % IDX_MOD);
  return (1 + IND_SIZE);
}

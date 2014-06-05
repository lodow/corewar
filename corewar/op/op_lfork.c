#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction and create a new process !
*/

void	debug_lfork(t_process *proc, short addr)
{
  my_putstr(proc->associated_champ->header.prog_name, 1, -1);
  my_putstr("\t", 1, 1);
  my_putstr(" lfork (", 1, -1);
  my_put_nbr(addr - proc->pc, 1);
  my_putstr(")\n", 1, -1);
}

int	op_lfork(t_process *proc, t_vm *vm)
{
  int	i;
  int	j;
  short	adrr;
  char	*tmp;

  i = 0;
  tmp = ((char*)(&adrr));
  j = IND_SIZE - 1;
  while (i < IND_SIZE)
    {
      tmp[i] = VM_MEM(proc->pc + 1 + j);
      j--;
      i++;
    }
  adrr = proc->pc + adrr;
  my_add_to_list(&(vm->process_list), create_new_process(vm, proc, adrr));
  DEBUGCALL(ISDEBUGMODE, debug_lfork(proc, adrr));
  return (3);
}

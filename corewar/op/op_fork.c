/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Jan 28 20:17:51 2013 luc sinet
*/

#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction and create a new process !
*/
int	op_fork(t_process *proc, t_vm *vm)
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
  adrr %= IDX_MOD;
  adrr = proc->pc + adrr;
  my_add_to_list(&(vm->process_list), create_new_process(vm, proc, adrr));
  printf("[%10s] fork (%d)\n", proc->associated_champ->header.prog_name, adrr - proc->pc);
  return (3);
}

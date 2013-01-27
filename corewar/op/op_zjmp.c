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
** \return the total size of the instruction or the new adresse to jump to !
*/
int	op_zjmp(t_process *proc, t_vm *vm)
{
  int	i;
  int	j;
  short	off_adrr;
  char	*tmp;

  if (proc->carry == 1)
    {
      i = 0;
      tmp = ((char*)(&off_adrr));
      j = IND_SIZE - 1;
      while (i < IND_SIZE)
        {
          tmp[i] = VM_MEM(proc->pc + 1 + j);
          j--;
          i++;
        }
      printf("%p executed instruction zjmp %+.10d at pc %d\n", (void*)proc, off_adrr, proc->pc);
      return (off_adrr % IDX_MOD);
    }
  printf("%p executed instruction zjmp -1 at pc %d\n", (void*)proc, proc->pc);
  return (1 + IND_SIZE);
}

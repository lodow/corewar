/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 16:52:26 2013 luc sinet
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
        printf("zjmp %d\n", off_adrr % IDX_MOD);
      return (off_adrr % IDX_MOD);
    }
    printf("zjmp -1\n");
  return (1 + IND_SIZE);
}

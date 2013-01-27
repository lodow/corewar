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
int	op_live(t_process *proc, t_vm *vm)
{
  int	i;
  int	j;
  char	*tmp;
  int	number;

  i = 0;
  tmp = ((char*)(&number));
  j = sizeof(int) - 1;
  while (i < sizeof(int))
    {
      tmp[i] = VM_MEM(proc->pc + 1 + j);
      j--;
      i++;
    }
  i = 0;
  while (vm->champs[i] != NULL)
    {
      if ((vm->champs[i])->number == number)
        (vm->champs[i])->alive += 1;
      i++;
    }
  printf("%p executed instruction live %+.10d at pc %d\n", (void*)proc, number, proc->pc);
  return (5);
}

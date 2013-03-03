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
int	op_aff(t_process *proc, t_vm *vm)
{
  int	reg1;
  char	cara;

  reg1 = proc->params_next_instr.params[1] - 1;
  if (reg1 >= 0 && reg1 < REG_NUMBER)
    {
      cara = proc->reg[reg1] % 256;
      my_putstr(&cara, 1, 1);
    }
  printf("[%10s] aff (reg%d=%d) -> %c\n", proc->associated_champ->header.prog_name, reg1, proc->reg[reg1], cara);
  return (3);
}

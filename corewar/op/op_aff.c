#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/

void	debug_aff(t_process *proc, int reg1, char cara)
{
  my_putstr(proc->associated_champ->header.prog_name, 1, -1);
  my_putstr("\t", 1, -1);
  my_putstr(" aff (reg", 1, -1);
  my_put_nbr(reg1, 1);
  my_putstr("=", 1, -1);
  my_put_nbr(proc->reg[reg1], 1);
  my_putstr(") -> ", 1, -1);
  my_put_nbr(cara, 1);
  my_putstr("\n", 1 , 1);
}

int	op_aff(t_process *proc, t_vm *vm)
{
  int	reg1;
  char	cara;

  reg1 = proc->params_next_instr.params[1] - 1;
  if (reg1 >= 0 && reg1 < REG_NUMBER)
    {
      cara = proc->reg[reg1] % 256;
      my_putstr(&cara, 1, 1);
      DEBUGCALL(ISDEBUGMODE, debug_aff(proc, reg1, cara));
    }
  return (3);
}

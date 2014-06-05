#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem ld the
** champs.
** \return the total size of the instruction !
*/

void	debug_lld(t_process *proc, int vtl, int reg)
{
  my_putstr(proc->associated_champ->header.prog_name, 1, -1);
  my_putstr("\t", 1 , 1);
  my_putstr(" lld (i@pc+", 1 , -1);
  my_put_nbr(vtl, 1);
  my_putstr("=", 1, 1);
  my_put_nbr(proc->reg[reg], 1);
  my_putstr(" -> reg", 1, -1);
  my_put_nbr(reg, 1);
  my_putstr(") carry = ", 1 , -1);
  my_put_nbr(proc->carry, 1);
  my_putstr("\n", 1, 1);
}

int	op_lld(t_process *proc, t_vm *vm)
{
  int	reg;
  int	vtl;

  vtl = 0;
  reg = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 1) + 1] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    {
      if (GET_TYPE_PARAMX(PARAMBYTE, 0) == 1)
        vtl = op_get_reg(proc, vm, 0);
      else if (GET_TYPE_PARAMX(PARAMBYTE, 0) == 2)
        vtl = op_get_dir(proc, vm, 0);
      else
        vtl = op_get_ind(proc, vm, 0, 0);
      proc->reg[reg] = vtl;
      proc->carry = is_byte_zero((char*) & (proc->reg[reg]), sizeof(int));
      DEBUGCALL(ISDEBUGMODE, debug_lld(proc, vtl, reg));
    }
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1) + 2);
}

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

int	op_or(t_process *proc, t_vm *vm)
{
  int	reg1;
  int	reg2;
  int	reg3;

  reg1 = proc->params_next_instr.params[1] - 1;
  reg2 = proc->params_next_instr.params[2] - 1;
  reg3 = proc->params_next_instr.params[3] - 1;
  if ((reg1 >= 0 && reg1 < REG_NUMBER) && (reg2 >= 0 && reg2 < REG_NUMBER) &&
      (reg3 >= 0 && reg3 < REG_NUMBER))
    {
      if ((proc->reg[reg3] = proc->reg[reg1] | proc->reg[reg2]) == 0)
        calc_carry(proc, is_byte_zero((char*)proc->reg[reg3], sizeof(int)));
      printf("%d or %d | %d = %d\n", proc->associated_champ->number, proc->reg[reg1], proc->reg[reg2], proc->reg[reg3]);
    }
  return (calc_instr_len_f_param_byte
          (proc->params_next_instr.params[0], MAX_ARGS_NUMBER));
}

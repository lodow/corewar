/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 16:52:51 2013 luc sinet
*/

#include	"operation.h"

int	op_and_dir(t_process *proc, t_vm *vm, int param)
{
  int	dir;

  dir = *(int*) & (proc->params_next_instr.params[NBPBYTE(PARAMBYTE, param) + 2]);
  return (dir);
}

int	op_and_reg(t_process *proc, t_vm *vm, int param)
{
  int	reg;

  reg = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, param) + 2] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    {
      return (proc->reg[reg]);
    }
  return (0);
}

int	op_and(t_process *proc, t_vm *vm)
{
  int	reg3;

  reg3 = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 2) + 2] - 1;
  if (reg3 >= 0 && reg3 < REG_NUMBER)
    {
      if (NBPBYTE(PARAMBYTE, 0) == 1)
        op_and_reg(proc, vm, 0);
      else if(NBPBYTE(PARAMBYTE, 0) == 2)
        op_and_dir(proc, vm, 0);
      calc_carry(proc, is_byte_zero((char*)proc->reg[reg3], sizeof(int)));
      /*      printf("%d and %d & %d = %d\n", proc->associated_champ->number, proc->reg[reg1], proc->reg[reg2], proc->reg[reg3]);*/
    }
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER));
}

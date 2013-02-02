/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 16:54:14 2013 luc sinet
*/

#include	"operation.h"

int	get_value_lldi_at_adrr(t_process *proc, t_vm *vm, int adrr)
{
  int	value;
  char	*tmp;

  value = 0;
  tmp = (char*)(&(value));
  tmp[0] = vm->mem[MOD_MEM(proc->pc + adrr + 0)];
  tmp[1] = vm->mem[MOD_MEM(proc->pc + adrr + 1)];
  tmp[2] = vm->mem[MOD_MEM(proc->pc + adrr + 2)];
  tmp[3] = vm->mem[MOD_MEM(proc->pc + adrr + 3)];
  switch_endian(tmp, sizeof(int));
  return (value);
}

int	op_lldi(t_process *proc, t_vm *vm)
{
  int	reg;
  int	val[2];
  int	i;

  i = 0;
  val[0] = 0;
  val[1] = 0;
  reg = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 2) + 1] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    {
      while ((i < 2) && (GET_TYPE_PARAMX(PARAMBYTE, i) != 0))
        {
          if (GET_TYPE_PARAMX(PARAMBYTE, i) == 1)
            val[i] = op_get_reg(proc, vm, i);
          else if (GET_TYPE_PARAMX(PARAMBYTE, i) == 2)
            val[i] = op_get_dir(proc, vm, i);
          else
            val[i] = op_get_ind(proc, vm, i, 0);
          i++;
        }
      proc->reg[reg] = get_value_ldi_at_adrr(proc, vm, val[0] + val[1]);
      proc->carry = is_byte_zero((char*) & (proc->reg[reg]), sizeof(int));
      printf("%d lldi %d,%d  adrr->%d = %d\n", proc->associated_champ->number, val[0], val[1], val[0] + val[1], proc->reg[reg]);
    }
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1) + 2);
}

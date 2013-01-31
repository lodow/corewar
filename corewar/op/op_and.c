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
  int	at;

  at = NBPBYTE(PARAMBYTE, param) + 1;
  dir = *((int*)(&(proc->params_next_instr.params[at])));
  switch_endian((char*)(&dir), sizeof(int));
  return (dir);
}

int	op_and_ind(t_process *proc, t_vm *vm, int param)
{
  short	adrr;
  int	dir;
  int	at;

  at = NBPBYTE(PARAMBYTE, param) + 1;
  adrr = *((short*)(&(proc->params_next_instr.params[at])));
  switch_endian((char*)(&adrr), sizeof(short));
  dir = *((int*)(&vm->mem[MOD_MEM(proc->pc + adrr)]));
  switch_endian((char*)(&dir), sizeof(int));
  return (dir);
}

int	op_and_reg(t_process *proc, t_vm *vm, int param)
{
  int	reg;

  reg = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, param) + 1] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    return (proc->reg[reg]);
  return (0);
}

int	op_and(t_process *proc, t_vm *vm)
{
  int	reg3;
  int	val[2];
  int	i;

  i = 0;
  val[0] = 0;
  val[1] = 0;
  reg3 = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 2) + 1] - 1;
  if (reg3 >= 0 && reg3 < REG_NUMBER)
    {
      while ((i < 2) && (GET_TYPE_PARAMX(PARAMBYTE, i) != 00))
        {
          if (GET_TYPE_PARAMX(PARAMBYTE, i) == 1)
            val[i] = op_and_reg(proc, vm, i);
          else if(GET_TYPE_PARAMX(PARAMBYTE, i) == 2)
            val[i] = op_and_dir(proc, vm, i);
          else
            val[i] = op_and_ind(proc, vm, i);
          i++;
        }
      proc->reg[reg3] = val[0] & val[1];
      calc_carry(proc, is_byte_zero((char*)&(proc->reg[reg3]), sizeof(int)));
      printf("%d and %d & %d = %d\n", proc->associated_champ->number, val[0], val[1], proc->reg[reg3]);
    }
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1) + 2);
}

/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 16:53:06 2013 luc sinet
*/

#include	"operation.h"

int	get_value_ldi_at_adrr(t_process *proc, t_vm *vm, int adrr)
{
  int	value;
  char	*tmp;

  value = 0;
  tmp = (char*)(&(value));
  tmp[0] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 0)];
  tmp[1] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 1)];
  tmp[2] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 2)];
  tmp[3] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 3)];
  switch_endian(tmp, sizeof(int));
  return (value);
}

short	get_value_ldi_b_adrr(t_process *proc, t_vm *vm)
{
  short	adrr;
  short	valat;
  char	*tmp;

  tmp = (char*)(&(adrr));
  tmp[0] = proc->params_next_instr.params[1];
  tmp[1] = proc->params_next_instr.params[2];
  switch_endian(tmp, sizeof(short));
  tmp = (char*)(&(valat));
  tmp[0] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 0)];
  tmp[1] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 1)];
  return (valat);
}

int	op_ldi(t_process *proc, t_vm *vm)
{
  int	reg;
  int	val[2];
  char	*tmp;

  val[0] = 0;
  val[1] = 0;
  reg = proc->params_next_instr.params[5] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    {
      val[0] = get_value_ldi_b_adrr(proc, vm);
      tmp = (char*)(&(val[1]));
      tmp[0] = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 1) + 1];
      tmp[0] = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 1) + 2];
      val[0] += val[1] % IDX_MOD;
      proc->reg[reg] = get_value_ldi_at_adrr(proc, vm, val[0]);
      proc->carry = is_byte_zero((char*)(&(proc->reg[reg])), sizeof(int));
      printf("%d ldi %d,%d  adrr->%d = %d\n", proc->associated_champ->number, val[0] - val[1], val[1], val[0], proc->reg[reg]);
    }
  return (7);
}


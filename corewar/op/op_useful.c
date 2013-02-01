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

int	op_get_dir(t_process *proc, t_vm *vm, int param)
{
  int	dir;
  int	at;

  at = NBPBYTE(PARAMBYTE, param) + 1;
  dir = *((int*)(&(proc->params_next_instr.params[at])));
  switch_endian((char*)(&dir), sizeof(int));
  return (dir);
}

int	op_get_ind(t_process *proc, t_vm *vm, int param, int idx_mod)
{
  short	adrr;
  int	dir;
  int	at;

  at = NBPBYTE(PARAMBYTE, param) + 1;
  adrr = *((short*)(&(proc->params_next_instr.params[at])));
  switch_endian((char*)(&adrr), sizeof(short));
  if (idx_mod)
    dir = *((int*)(&vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD))]));
  else
    dir = *((int*)(&vm->mem[MOD_MEM(proc->pc + (adrr))]));
  switch_endian((char*)(&dir), sizeof(int));
  return (dir);
}

int	op_get_reg(t_process *proc, t_vm *vm, int param)
{
  int	reg;

  reg = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, param) + 1] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    return (proc->reg[reg]);
  return (0);
}

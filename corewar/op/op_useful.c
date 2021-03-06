#include	"operation.h"

int	op_get_ind_as_dir(t_process *proc, t_vm *vm, int param)
{
  short	value;
  int	at;

  value = 0;
  at = NBPBYTE(PARAMBYTE, param) + 1;
  value = *((short*)(&(proc->params_next_instr.params[at])));
  switch_endian((char*)(&value), sizeof(short));
  return (value);
}

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
  char	var[4];
  int	dir;
  int	at;

  at = NBPBYTE(PARAMBYTE, param) + 1;
  adrr = *((short*)(&(proc->params_next_instr.params[at])));
  switch_endian((char*)(&adrr), sizeof(short));
  if (idx_mod)
    {
      var[0] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 0)];
      var[1] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 1)];
      var[2] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 2)];
      var[3] = vm->mem[MOD_MEM(proc->pc + (adrr % IDX_MOD) + 3)];
    }
  else
    {
      var[0] = vm->mem[MOD_MEM(proc->pc + (adrr) + 0)];
      var[1] = vm->mem[MOD_MEM(proc->pc + (adrr) + 1)];
      var[2] = vm->mem[MOD_MEM(proc->pc + (adrr) + 2)];
      var[3] = vm->mem[MOD_MEM(proc->pc + (adrr) + 3)];
    }
  dir = *((int*)(var));
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

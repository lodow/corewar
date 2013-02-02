/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Feb  2 18:11:03 2013 luc sinet
*/

#include	"operation.h"

void	op_st_reg(t_process *proc, t_vm *vm, int reg)
{
  int	reg2;

  reg2 = proc->params_next_instr.params[2] - 1;
  if (reg2 >= 0 && reg2 < REG_NUMBER)
    {
      proc->reg[reg2] = proc->reg[reg];
      proc->carry = is_byte_zero((char*) & (proc->reg[reg]), sizeof(int));
      printf("st reg%d, reg%d\n", reg, reg2);
    }
}

void	op_st_dir(t_process *proc, t_vm *vm, int reg)
{
  int	adrr;
  char	*tmp;

  tmp = ((char*)(&(adrr)));
  tmp[0] = proc->params_next_instr.params[2];
  tmp[1] = proc->params_next_instr.params[3];
  tmp[2] = proc->params_next_instr.params[4];
  tmp[3] = proc->params_next_instr.params[5];
  switch_endian(tmp, sizeof(int));
  tmp = ((char*)(&(proc->reg[reg])));
  vm->mem[MOD_MEM(adrr + 0)] = tmp[3];
  vm->mem[MOD_MEM(adrr + 1)] = tmp[2];
  vm->mem[MOD_MEM(adrr + 2)] = tmp[1];
  vm->mem[MOD_MEM(adrr + 3)] = tmp[0];
  proc->carry = is_byte_zero((char*) & (proc->reg[reg]), sizeof(int));
}

void	op_st_ind(t_process *proc, t_vm *vm, int reg)
{
  short	adrr;
  char	*tmp;

  tmp = ((char*)(&(adrr)));
  tmp[0] = proc->params_next_instr.params[2];
  tmp[1] = proc->params_next_instr.params[3];
  switch_endian(tmp, sizeof(short));
  adrr %= IDX_MOD;
  tmp = ((char*)(&(proc->reg[reg])));
  vm->mem[MOD_MEM(proc->pc + adrr + 0)] = tmp[3];
  vm->mem[MOD_MEM(proc->pc + adrr + 1)] = tmp[2];
  vm->mem[MOD_MEM(proc->pc + adrr + 2)] = tmp[1];
  vm->mem[MOD_MEM(proc->pc + adrr + 3)] = tmp[0];
  printf("st reg%d,%d\n", reg, adrr);
  proc->carry = is_byte_zero((char*) & (proc->reg[reg]), sizeof(int));
}

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_st(t_process *proc, t_vm *vm)
{
  int	reg;

  reg =  proc->params_next_instr.params[1] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    {
      if (GET_TYPE_PARAMX(PARAMBYTE, 1) == 1)
        op_st_reg(proc, vm, reg);
      else if (GET_TYPE_PARAMX(PARAMBYTE, 1) == 2)
        op_st_dir(proc, vm, reg);
      else
        op_st_ind(proc, vm, reg);
    }
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1) + 2);
}

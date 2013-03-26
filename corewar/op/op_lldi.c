/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Mar 25 17:27:33 2013 luc sinet
*/

#include	"operation.h"

void	debug_lldi(t_process *proc, int *val, int reg)
{
  my_putstr(proc->associated_champ->header.prog_name, 1, -1);
  my_putstr("\t", 1 , 1);
  my_putstr(" lldi (i@*(pc+", 1 , -1);
  my_put_nbr(val[0] - val[1], 1);
  my_putstr("=", 1 , 1);
  my_put_nbr(val[1], 1);
  my_putstr("=", 1, 1);
  my_put_nbr(proc->reg[reg], 1);
  my_putstr(" -> reg", 1, -1);
  my_put_nbr(reg, 1);
  my_putstr(") carry = ", 1 , -1);
  my_put_nbr(proc->carry, 1);
  my_putstr("\n", 1, 1);
}

int	get_value_lldi_at_adrr(t_process *proc, t_vm *vm, int adrr)
{
  int	value;
  char	*tmp;

  value = 0;
  tmp = (char*)(&(value));
  tmp[0] = vm->mem[MOD_MEM(proc->pc + (adrr) + 0)];
  tmp[1] = vm->mem[MOD_MEM(proc->pc + (adrr) + 1)];
  tmp[2] = vm->mem[MOD_MEM(proc->pc + (adrr) + 2)];
  tmp[3] = vm->mem[MOD_MEM(proc->pc + (adrr) + 3)];
  switch_endian(tmp, sizeof(int));
  return (value);
}

short	get_value_lldi_b_adrr(t_process *proc, t_vm *vm)
{
  short	adrr;
  short	valat;
  char	*tmp;

  tmp = (char*)(&(adrr));
  tmp[0] = proc->params_next_instr.params[1];
  tmp[1] = proc->params_next_instr.params[2];
  switch_endian(tmp, sizeof(short));
  tmp = (char*)(&(valat));
  tmp[0] = vm->mem[MOD_MEM(proc->pc + (adrr) + 0)];
  tmp[1] = vm->mem[MOD_MEM(proc->pc + (adrr) + 1)];
  return (valat);
}

int	op_lldi(t_process *proc, t_vm *vm)
{
  int	reg;
  int	val[2];
  char	*tmp;

  val[0] = 0;
  val[1] = 0;
  reg = proc->params_next_instr.params[5] - 1;
  if (reg >= 0 && reg < REG_NUMBER)
    {
      val[0] = get_value_lldi_b_adrr(proc, vm);
      tmp = (char*)(&(val[1]));
      tmp[0] = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 1) + 1];
      tmp[0] = proc->params_next_instr.params[NBPBYTE(PARAMBYTE, 1) + 2];
      proc->reg[reg] = get_value_lldi_at_adrr(proc, vm, val[0]);
      proc->carry = is_byte_zero((char*)(&(proc->reg[reg])), sizeof(int));
      DEBUGCALL(ISDEBUGMODE, debug_lldi(proc, val, reg));
    }
  return (7);
}

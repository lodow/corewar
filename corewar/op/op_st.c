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

int	op_st_reg(t_process *proc, t_vm *vm, int reg1)
{
  int	reg2;
  int	ok;

  ok = 0;
  reg2 = proc->params_next_instr.params[2] - 1;
  if (reg2 >= 0 && reg2 < REG_NUMBER)
    {
      ok = 1;
      proc->reg[reg1] = proc->reg[reg2];
    }
  return (ok);
}

int	op_st_dir(t_process *proc, t_vm *vm, int reg1)
{
  char	*tmp;
  int	adrr;
  int	i;
  int	j;

  i = 0;
  tmp = ((char*)(&adrr));
  j = DIR_SIZE - 1;
  while (i < DIR_SIZE)
    {
      tmp[i] = proc->params_next_instr.params[2 + j];
      j--;
      i++;
    }
  i = 0;
  tmp = ((char*)(&(proc->reg[reg1])));
  while (i < DIR_SIZE)
    {
      VM_MEM(i) = tmp[i];
      i++;
    }
  return (1);
}

int	op_st_ind(t_process *proc, t_vm *vm, int reg1)
{
  char	*tmp;
  short	adrr;
  int	i;
  int	j;

  i = 0;
  tmp = ((char*)(&adrr));
  j = IND_SIZE - 1;
  while (i < IND_SIZE)
    {
      tmp[i] = proc->params_next_instr.params[2 + j];
      j--;
      i++;
    }
  i = 0;
  tmp = ((char*)(&(proc->reg[reg1])));
  while (i < IND_SIZE)
    {
      VM_MEM(proc->pc + ((adrr + i) % IDX_MOD)) = tmp[i];
      i++;
    }
  return (1);
}

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_st(t_process * proc, t_vm * vm)
{
  int	reg1;
  char	type_param2;
  int	ch_carry;
  int	carry;

  ch_carry = 0;
  carry = proc->carry;
  type_param2 = GET_TYPE_PARAMX(proc->params_next_instr.params[0], 1);
  reg1 = proc->params_next_instr.params[1] - 1;
  if ((reg1 >= 0 && reg1 < REG_NUMBER) && (type_param2 != 0x00))
    {
      carry = is_byte_zero((char*)&(proc->reg[reg1]), sizeof(int));
      if (type_param2 == 0x01)
        ch_carry = op_st_reg(proc, vm, reg1);
      else if(type_param2 == 0x02)
        ch_carry = op_st_ind(proc, vm, reg1);
      else
        ch_carry = op_st_dir(proc, vm, reg1);
    }
  if (ch_carry)
    calc_carry(proc, carry);
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1));
}

#include	"operation.h"

void	debug_xor(t_process *proc, int *val, int reg3)
{
  my_putstr(proc->associated_champ->header.prog_name, 1 , -1);
  my_putstr("\t", 1, 1);
  my_putstr(" xor (", 1, -1);
  my_put_nbr(val[0], 1);
  my_putstr(" ^ ", 1, 3);
  my_put_nbr(val[1], 1);
  my_putstr(" = reg", 1, 6);
  my_put_nbr(reg3, 1);
  my_putstr("=", 1, 1);
  my_put_nbr(proc->reg[reg3], 1);
  my_putstr(") carry = ", 1, 10);
  my_put_nbr(proc->carry, 1);
  my_putstr("\n", 1, 1);
}

int	op_xor(t_process *proc, t_vm *vm)
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
            val[i] = op_get_reg(proc, vm, i);
          else if (GET_TYPE_PARAMX(PARAMBYTE, i) == 2)
            val[i] = op_get_dir(proc, vm, i);
          else
            val[i] = op_get_ind_as_dir(proc, vm, i);
          i++;
          proc->reg[reg3] = val[0] ^ val[1];
        }
      proc->carry = is_byte_zero((char*) & (proc->reg[reg3]), sizeof(int));
    }
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1) + 2);
}

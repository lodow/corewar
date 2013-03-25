/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Mar 25 15:54:40 2013 luc sinet
*/

#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/

void	debug_add(t_process *proc, int reg1, int reg2, int reg3)
{
  my_putstr("\t", 1, 1);
  my_putstr(proc->associated_champ->header.prog_name, 1 , -1);
  my_putstr(" add (reg)", 1 ,-1);
  my_put_nbr(reg1, 1);
  my_putstr("=", 1, 1);
  my_put_nbr(proc->reg[reg1]);
  my_putstr(" + reg", 1, 6);
  my_put_nbr(reg2, 1);
  my_putstr("=", 1, 1);
  my_put_nbr(proc->reg[reg2]);
  my_putstr(" = reg", 1, 6);
  my_put_nbr(reg3, 1);
  my_putstr("=", 1, 1);
  my_put_nbr(proc->reg[reg3]);
  my_putstr(") carry = ", 1, 10);
  my_put_nbr(proc->carry, 1);
  my_putstr("\n", 1, 1);
}

int	op_add(t_process *proc, t_vm *vm)
{
  int	reg1;
  int	reg2;
  int	reg3;

  reg1 = proc->params_next_instr.params[1] - 1;
  reg2 = proc->params_next_instr.params[2] - 1;
  reg3 = proc->params_next_instr.params[3] - 1;
  if ((reg1 >= 0 && reg1 < REG_NUMBER) && (reg2 >= 0 && reg2 < REG_NUMBER) &&
      (reg3 >= 0 && reg3 < REG_NUMBER))
    {
      proc->reg[reg3] = proc->reg[reg1] + proc->reg[reg2];
      proc->carry = is_byte_zero((char*)&proc->reg[reg3], sizeof(int));
    }
  return (5);
}

/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sat Feb  2 08:01:11 2013 luc sinet
*/

#include	"operation.h"

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_st(t_process * proc, t_vm * vm)
{
  /* int	reg1; */
  /* char	type_param2; */

  /* type_param2 = GET_TYPE_PARAMX(proc->params_next_instr.params[0], 1); */
  /* reg1 = proc->params_next_instr.params[1] - 1; */
  /* if ((reg1 >= 0 && reg1 < REG_NUMBER) && (type_param2 != 0x00)) */
  /*   { */
  /*     carry = is_byte_zero((char*) & (proc->reg[reg1]), sizeof(int)); */
  /*     if (type_param2 == 0x01) */
  /*       ch_carry = op_st_reg(proc, vm, reg1); */
  /*     else if(type_param2 == 0x02) */
  /*       ch_carry = op_st_ind(proc, vm, reg1); */
  /*     else */
  /*       ch_carry = op_st_dir(proc, vm, reg1); */
  /*   } */
  /* if (ch_carry) */
  /*   proc->carry = carry; */
  return (NBPBYTE(proc->params_next_instr.params[0], MAX_ARGS_NUMBER - 1));
}

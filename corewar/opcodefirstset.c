/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

/*
** Some instruction (live, ld,...)
*/
int	op_live(t_process *proc)
{

}

int	op_load(t_process *proc)
{
  char	*val_t_ld;
  char	*tmp;
  char	tmp_type;
  char	param_type;
  int	instr_size;
  char	registrnb;

  param_type = proc->mem[MOD_MEM(proc->pc + 1)];
  instr_size = 2;
  tmp_type = GET_TYPE_PARAMX(param_type, 0);
  val_t_ld = get_value_f_param_type(tmp_type, instr_size, proc);
  instr_size += op_param_size(GET_TYPE_PARAMX(param_type, 0));
  if ((tmp_type = GET_TYPE_PARAMX(param_type, 1)) == T_REG)
    {
      tmp = get_value_f_param_type(tmp_type, instr_size, proc);
      registrnb = tmp[0];
      free(tmp);
    }
  if (registrnb < REG_NUMBER)
    my_strncpy(proc[(int)registrnb], val_t_ld, REG_SIZE);
  instr_size += op_param_size(GET_TYPE_PARAMX(param_type, 1));
  proc->nb_cycle_t_next = 2;
  return (instr_size);
}

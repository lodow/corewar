/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morissetňňňŅņŇ
*/

#include	"operation.h"

char	*load_param1(char type)
{

}

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \return the total size of the instruction !
*/
int	op_load(t_process *proc, t_vm *vm)
{
  char	*src;
  char	tmpchar;
  char	typep1;

  typep1 = GET_TYPE_PARAMX(VM_MEM(proc->pc + 1), 0);
  src = NULL;
  if (typep1 == T_REG)
    {
      tmpchar = VM_MEM(proc->pc + NBPBYTE(VM_MEM(proc->pc + 1), 0) + 2) - 1;
      if (tmpchar < REG_NUMBER)
        src = proc->reg[(int)tmpchar];
cpy_t_registre(src, )
    }
  else if (typep1 == T_DIR)
  {
src =
  }

    return (NBPBYTE(VM_MEM(proc->pc + 1), MAX_ARGS_NUMBER) + 2);
}

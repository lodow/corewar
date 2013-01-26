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

/*
** \param[in] type The params byte
** \param[in] nbmax  How much params take into
** \return The total size of all those params
*/
int	calc_instr_len_f_param_byte(char type, int nbmax)
{
  int	tsize;
  char	tmpstype;
  int	i;

  i = 0;
  tsize = 0;
  while ((i < nbmax) && (i < MAX_ARGS_NUMBER) && (tmpstype != 0x0))
    {
      if (tmpstype == T_REG)
        tsize += 1;
      else if (tmpstype == T_DIR)
        tsize += DIR_SIZE;
      else
        tsize += IND_SIZE;
      i++;
      tmpstype = GET_TYPE_PARAMX(type, i);
    }
  return (tsize);
}

/*
** Return if the src is zero on size byte
*/
int	is_byte_zero(char *src, int size)
{
  int	i;

  i = 0;
  if (src != NULL)
    while (i < size)
      {
        if (src[i] != 0)
          return (0);
        i++;
      }
  return (1);
}

void	calc_carry(t_process *proc, int is_zero)
{
  if (is_zero == 0)
    proc->carry = 1;
  else
    proc->carry = 0;
}

/*
** \param[in] proc A ptr on the process executing the instrcution !
** \param[in] vm A ptr on the vm useful to get the ptr on the vmmem and the
** champs.
** \param[in] parambyte The param byte of the instruction
** \param[in] x The parma number x
** \return A malloc byte tab cpy of the param (Resovle ind param)
*/
char	*get_paramx(t_vm *vm, t_process *proc, char parambyte, int x)
{
  char	type;
  int	off;
  char	tmpchar;
  char	*res;

  type = GET_TYPE_PARAMX(parambyte, x);
  off = NBPBYTE(parambyte, x);
  if (type != T_REG && type != T_DIR)
    return (NULL);
  if (type == T_REG)
    {
      if ((res = malloc(REG_SIZE * sizeof(char))) == NULL)
        return (NULL);
      tmpchar = VM_MEM(proc->pc + 2 + off) - 1;
      if (tmpchar < REG_NUMBER)
        cpy_t_registre(proc->reg[(int)tmpchar], (t_reg*)&res);
    }
  else
    {
      if ((res = malloc(IND_SIZE * sizeof(char))) == NULL)
        return (NULL);
      cpy_t_registre((char*)&VM_MEM(proc->pc + 2 + off), (t_reg*)&res);
    }
  switch_endian(res, REG_SIZE);
  return (res);
}

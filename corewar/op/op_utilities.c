/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Jan 29 16:42:42 2013 luc sinet
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
  tmpstype = GET_TYPE_PARAMX(type, i);
  while ((i < nbmax) && (i < (MAX_ARGS_NUMBER - 1)) && (tmpstype != 0x0))
    {
      tmpstype = GET_TYPE_PARAMX(type, i);
      if (tmpstype == T_REG)
        tsize += 1;
      else if (tmpstype == T_DIR)
        tsize += DIR_SIZE;
      else
        tsize += IND_SIZE;
      i++;
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
  if (is_zero)
    proc->carry = 1;
  else
    proc->carry = 0;
}

int	toggle_val(int val)
{
  return ((val + 1) % 2);
}

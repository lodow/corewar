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
  while (i < size)
    {
      if (src[i] != 0)
        return (0);
      i++;
    }
  return (1);
}

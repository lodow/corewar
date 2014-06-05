#include "parse_cmd.h"
#include "asm.h"

extern	t_op	op_tab[];

int	chose_func(t_param *param, char *str, int i, t_cmd *cmd)
{
  int	j;
  int	(*ptr[16])(char *, int, t_param *, t_cmd *);

  j = 0;
  ptr[0] = &live;
  ptr[1] = &ld;
  ptr[2] = &st;
  ptr[3] = &add_sub;
  ptr[4] = &add_sub;
  ptr[5] = &and_or_xor;
  ptr[6] = &and_or_xor;
  ptr[7] = &and_or_xor;
  ptr[8] = &zjump;
  ptr[9] = &ldi_lldi;
  ptr[10] = &sti;
  ptr[11] = &lfork;
  ptr[12] = &ld;
  ptr[13] = &ldi_lldi;
  ptr[14] = &lfork;
  ptr[15] = &laff;
  while (my_instructcmp(&(str[i]), op_tab[j].mnemonique, ' ') == 0 && j < 16)
    j++;
  if (j == 16)
    return (-1);
  return (ptr[j](str, i, param, cmd));
}

int	my_cmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != 0 && str2[i] != 0)
    {
      if (str1[i] != str2[i])
        return (0);
      i++;
    }
  if (str2[i] != 0 || (str1[i] != ' ' &&
		       str1[i] != SEPARATOR_CHAR &&
		       str1[i] != 0))
    return (0);
  return (1);
}

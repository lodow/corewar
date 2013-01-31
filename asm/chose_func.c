/*
** chose_func.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 18:45:02 2013 maxime lavandier
** Last update Thu Jan 31 01:54:49 2013 maxime lavandier
*/

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
  while (my_instructcmp(str, op_tab[j].mnemonique, ' ') == 0 && j < 16)
    j++;
  if (j == 16)
    return (0);
  return (ptr[j](str, i ,param, cmd));
}

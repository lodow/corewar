/*
** chose_func.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 18:45:02 2013 maxime lavandier
** Last update Wed Jan 30 19:55:59 2013 maxime lavandier
*/

#include "parse_cmd.h"

int	nothing(char *str, int i, t_param *param, t_cmd *cmd)
{
  return (1);
}

int	chose_func(t_param *param, char *str, int i, t_cmd *cmd)
{
  int	(*ptr[11])(char *, int, t_param *, t_cmd *);

  ptr[0] = &nothing;
  ptr[1] = &live;
  ptr[2] = &ld;
  ptr[3] = &st;
  ptr[4] = &add_sub;
  ptr[5] = &and_or_xor;
  ptr[6] = &zjump;
  ptr[7] = &ldi_lldi;
  ptr[8] = &sti;
  ptr[9] = &lfork;
  ptr[10] = &laff;
  if ((*ptr[my_begincmp(str, "live")])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "ld") * 2])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "st") * 3])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "add") * 4])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "sub") * 4])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "and") * 5])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "or") * 5])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "xor") * 5])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "zjmp") * 6])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "ldi") * 7])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "sti") * 8])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "fork") * 9])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "lld") * 2])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "lldi") * 7])(str, i, param, cmd) &&
      (ptr[my_begincmp(str, "lfork") * 9])(str, i, param, cmd) &&
      (ptr[((my_begincmp(str, "aff")) * 10)])(str, i, param, cmd))
    return (0);
  return (-1);
}

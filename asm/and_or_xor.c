/*
** and_or_xor.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 16:32:57 2013 maxime lavandier
** Last update Wed Jan 30 23:46:24 2013 Welanor
*/

#include "parse_cmd.h"

int	and_or_xor(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'a')
    param->param[0] = 0x6;
  else if (str[i] == 'o')
    param->param[0] = 0x7;
  else if (str[i] == 'x')
    param->param[0] = 0x8;
  else
    return (-1);
  params(str, i , param, cmd);
  if (param->param[1] & 4)
    return (0);
  return (-1);
}

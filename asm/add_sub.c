/*
** add_sub.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 15:07:26 2013 maxime lavandier
** Last update Thu Jan 31 16:28:25 2013 Welanor
*/

#include "parse_cmd.h"

int	add_sub_param(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'r')
    registre(param, str, i);
  else
    return (-1);
  i++;
  while (str[i] != 0 && str[i] != 'r')
    i++;
  if (str[i] == 'r')
    registre(param, str, i);
  else
    return (-1);
  i++;
  while (str[i] != 0 && str[i] != 'r')
    i++;
  if (str[i] == 'r')
    registre(param, str, i);
  else
    return (-1);
  /*  while (str[i] != 0 && str[i] != 'r')
    i++;
  if (str[i] == 0)
    return (-1);
  */ return (0);
}


int	add_sub(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'a')
    param->param[0] = 0x4;
  else if (str[i] == 's')
    param->param[0] = 0x5;
  else
    return (-1);
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  param->param[1] = 0b01010100;
  if (add_sub_param(str, i, param, cmd) == -1)
    return (-1);
  return (0);
}

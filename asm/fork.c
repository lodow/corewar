/*
** fork.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 17:14:12 2013 maxime lavandier
** Last update Thu Mar  7 16:36:41 2013 Adrien
*/

#include "parse_cmd.h"

int	lfork(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'f')
    param->param[0] = 0xc;
  else if (str[i] == 'l')
    param->param[0] = 0xf;
  else
    return (-1);
  param->lenght = 1;
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] == DIRECT_CHAR)
    i++;
  indirect(param, str, i, cmd);
  return (0);
}

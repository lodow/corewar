/*
** aff.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 17:49:25 2013 maxime lavandier
** Last update Thu Jan 31 11:17:18 2013 maxime lavandier
*/

#include "parse_cmd.h"

int	laff(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->param[0] = 0x10;
  param->param[1] = 0b01000000;
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] != 'r')
    return (-1);
  registre(param, str, i, cmd->nb);
  return (0);
}

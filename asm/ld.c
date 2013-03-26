/*
** ld.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 15:31:06 2013 maxime lavandier
** Last update Thu Mar  7 16:37:42 2013 Adrien
*/

#include "parse_cmd.h"

int	ld_param(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'r')
    {
      registre(param, str, i, cmd->nb);
      i++;
      while (str[i] != 'r' && str[i] != 0)
	i++;
      if (str[i] == 0)
	return (-1);
      param->param[1] = 0b01010000;
      registre(param, str, i, cmd->nb);
    }
  else
    {
      indirect(param, str, i, cmd);
      while (str[i] != 'r' && str[i] != 0)
	i++;
      if (str[i] == 0)
	return (-1);
      param->param[1] = 0b11010000;
      registre(param, str, i, cmd->nb);
    }
  return (0);
}

int	ld(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i + 1] == 'l')
    param->param[0] = 0xd;
  else if (str[i] == 'l')
    param->param[0] = 0x2;
  else
    return (-1);
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] == DIRECT_CHAR)
    {
      direct(param, str, i, cmd);
      while (str[i] != 'r' && str[i] != 0)
	i++;
      if (str[i] == 0)
	return (-1);
      param->param[1] = 0b10010000;
      registre(param, str, i, cmd->nb);
    }
  else if (ld_param(str, i, param, cmd) == -1)
    return (-1);
  return (0);
}

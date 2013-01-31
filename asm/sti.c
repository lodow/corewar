/*
** sti.c for sti in /home/dellam_a/Projet/corewar/asm
**
** Made by Adrien
** Login   <dellam_a@epitech.eu>
**
** Started on  Wed Jan 30 17:53:57 2013 Adrien
** Last update Thu Jan 31 07:00:42 2013 maxime lavandier
*/

#include "parse_cmd.h"

void	sti_param(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'r')
    registre(param, str, i);
  else if (str[i] == LABEL_CHAR)
    direct(param, str, i, cmd);
  else
    indirect(param, str, i, cmd);
}

int	sti(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->param[0] = 0xb;
  while (str[i] != ' ' && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  sti_param(str, i, param, cmd);
  if ((i = next(str, i)) == -1)
    return (-1);
  sti_param(str, i, param, cmd);
  if ((i = next(str, i)) == -1)
    return (-1);
  sti_param(str, i, param, cmd);
  return (0);
}


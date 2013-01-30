/*
** zjump.c for zjump in /home/dellam_a/Projet/corewar/asm
** 
** Made by dellam_a
** Login   <dellam_a@epitech.eu>
** 
** Started on  Wed Jan 30 16:22:02 2013 Adrien
** Last update Wed Jan 30 23:52:47 2013 Welanor
*/

#include "parse_cmd.h"

int	zjump(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->param[0] = 0x1;
  param->lenght -= 0x1;
  while (str[i] != ' ' && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] == DIRECT_CHAR)
    i++;
  indirect(param, str, i, cmd);
  return (0);
}

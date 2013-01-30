/*
** ldi.c for ldi in /home/dellam_a/Projet/corewar/asm
** 
** Made by Adrien
** Login   <dellam_a@epitech.eu>
** 
** Started on  Wed Jan 30 16:55:04 2013 Adrien
** Last update Wed Jan 30 23:49:37 2013 Welanor
*/

#include "../misc/op.h"
#include "parse_cmd.h"

int	next(char *str, int i)
{
  while (str[i] != SEPARATOR_CHAR && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  return (i);
}

int	ldi_lldi(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->param[0] = 0xa;
  while (str[i] != ' ' && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] == 'r')
    return (-1);
  else if (str[i] == LABEL_CHAR)
    i++;
  indirect(param, &str[i], i, cmd);
  if ((i = next(str, i)) == -1)
    return (-1);
  if (str[i] == 'r')
    return (-1);
  else if (str[i] == LABEL_CHAR)
    i++;
  indirect(param, &str[i], i, cmd);
  if ((i = next(str, i)) == -1)
    return (-1);
  if (str[i] != 'r')
    return (-1);
  registre(param, str, i);
  return (0);
}

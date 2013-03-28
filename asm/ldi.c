/*
** ldi.c for ldi in /home/dellam_a/Projet/corewar/asm
**
** Made by Adrien
** Login   <dellam_a@epitech.eu>
**
** Started on  Wed Jan 30 16:55:04 2013 Adrien
** Last update Thu Jan 31 16:03:11 2013 Welanor
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

int	ldi_lldi_param(char *str, int i, t_param *param, t_cmd *cmd)
{
  if ((i = next(str, i)) == -1)
    return (-1);
  if (str[i] == 'r')
    return (-1);
  else if (str[i] == DIRECT_CHAR)
    {
      i++;
      param->param[1] <<= 2;
      param->param[1] += 2;
    }
  else
    {
      param->param[1] <<= 2;
      param->param[1] += 3;
    }
  indirect(param, str, i, cmd);
  if ((i = next(str, i)) == -1)
    return (-1);
  if (str[i] != 'r')
    return (-1);
  param->param[1] <<= 2;
  param->param[1] += 1;
  param->param[1] <<= 2;
  registre(param, str, i, cmd->nb);
  return (0);
}

int	ldi_lldi(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->param[0] = (str[i + 1] == 'l' ? 0xe : 0xa);
  param->param[1] = 0;
  while (str[i] != ' ' && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] == 'r')
    return (-1);
  else if (str[i] == DIRECT_CHAR)
    {
      i++;
      param->param[1] <<= 2;
      param->param[1] += 2;
    }
  else
    {
      param->param[1] <<= 2;
      param->param[1] += 3;
    }
  indirect(param, str, i, cmd);
  return (ldi_lldi_param(str, i, param, cmd));
}

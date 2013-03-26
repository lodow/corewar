/*
** sti.c for sti in /home/dellam_a/Projet/corewar/asm
**
** Made by Adrien
** Login   <dellam_a@epitech.eu>
**
** Started on  Wed Jan 30 17:53:57 2013 Adrien
** Last update Thu Jan 31 15:46:20 2013 Welanor
*/

#include "parse_cmd.h"

void	sti_param(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'r')
    {
      registre(param, str, i, cmd->nb);
      param->param[1] <<= 2;
      param->param[1] += 1;
    }
  else if (str[i] == DIRECT_CHAR)
    {
      i++;
      indirect(param, str, i, cmd);
      param->param[1] <<= 2;
      param->param[1] += 2;
    }
  else
    {
      indirect(param, str, i, cmd);
      param->param[1] <<= 2;
      param->param[1] += 3;
    }
}

void	sti_last(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'r')
    {
      i++;
      indirect(param, str, i, cmd);
      param->param[1] <<= 2;
      param->param[1] += 1;
    }
  else if (str[i] == DIRECT_CHAR)
    {
      i++;
      indirect(param, str, i, cmd);
      param->param[1] <<= 2;
      param->param[1] += 2;
    }
  else
    {
      indirect(param, str, i, cmd);
      param->param[1] <<= 2;
      param->param[1] += 3;
    }
}

int	sti(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->param[0] = 0xb;
  param->param[1] = 0;
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
  param->param[1] <<= 2;
  return (0);
}


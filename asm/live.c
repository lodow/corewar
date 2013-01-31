/*
** live.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 30 15:21:31 2013 maxime lavandier
** Last update Thu Jan 31 08:47:49 2013 maxime lavandier
*/

#include "parse_cmd.h"

int	live(char *str, int i, t_param *param, t_cmd *cmd)
{
  printf ("salut\n");
  param->param[0] = 0x1;
  param->lenght = 1;
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  direct(param, str, i , cmd);
  return (0);
}

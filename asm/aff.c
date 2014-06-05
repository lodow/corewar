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

#include "parse_cmd.h"

int	zjump(char *str, int i, t_param *param, t_cmd *cmd)
{
  param->param[0] = 0x9;
  while (str[i] != ' ' && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (-1);
  i++;
  if (str[i] == DIRECT_CHAR)
    i++;
  param->lenght = 1;
  indirect(param, str, i, cmd);
  return (0);
}

#include "parse_cmd.h"

int	live(char *str, int i, t_param *param, t_cmd *cmd)
{
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

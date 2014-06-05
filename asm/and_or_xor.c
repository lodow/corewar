#include "parse_cmd.h"

int	and_or_xor(char *str, int i, t_param *param, t_cmd *cmd)
{
  if (str[i] == 'a')
    param->param[0] = 0x6;
  else if (str[i] == 'o')
    param->param[0] = 0x7;
  else if (str[i] == 'x')
    param->param[0] = 0x8;
  else
    return (-1);
  params(str, i , param, cmd);
  if (param->param[1] & 4)
    return (0);
  return (-1);
}

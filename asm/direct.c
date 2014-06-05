#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"
#include "../misc/nb_func.h"

int	predirect(t_param *param, char *str, int i, t_cmd *cmd)
{
  int	j;
  int	nb;

  if (str[i + 1] == LABEL_CHAR)
    {
      j = 0;
      i += 2;
      while (my_cmp(&str[i], cmd->lab[j].label) != 0
	     && j < cmd->lablengh - 1)
	j++;
      nb = cmd->lab[j].adress - cmd->pc;
    }
  else
    nb = my_getnbr(&(str[i + 1]));
  return (nb);
}

void	direct(t_param *param, char *str, int i, t_cmd *cmd)
{
  int	nb;

  nb = predirect(param, str, i, cmd);
  if ((param->param = realloc(param->param, param->lenght + DIR_SIZE)) == 0)
    exit(0);
  param->param[param->lenght + DIR_SIZE - 1] = 0;
  param->param[param->lenght + DIR_SIZE - 2] = 0;
  param->param[param->lenght + DIR_SIZE - 3] = 0;
  param->param[param->lenght + DIR_SIZE - 4] = 0;
  param->param[param->lenght + DIR_SIZE - 1] |= nb;
  nb = nb >> 8;
  param->param[param->lenght + DIR_SIZE - 2] |= nb;
  nb = nb >> 8;
  param->param[param->lenght + DIR_SIZE - 3] |= nb;
  nb = nb >> 8;
  param->param[param->lenght + DIR_SIZE - 4] |= nb;
  param->lenght += DIR_SIZE;
}

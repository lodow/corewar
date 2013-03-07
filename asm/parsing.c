/*
** parsing.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Fri Jan 25 16:45:04 2013 maxime lavandier
** Last update Thu Mar  7 16:31:55 2013 Adrien
*/

#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"
#include "../misc/nb_func.h"

void	registre(t_param *param, char *str, int i)
{
  int	nb;
  char	nbr;

  nb = my_getnbr(&(str[i + 1]));
  nbr = (char) nb;
  if (nb > REG_NUMBER || nb < 1)
    {
      my_putstr("registre trop grand\n", 2, -1);
      exit(0);
    }
  if ((param->param = realloc(param->param, param->lenght + 1)) == NULL)
    exit(0);
  param->param[param->lenght] = nbr;
  param->lenght += 1;
}

void	indirect(t_param *param, char *str, int i, t_cmd *cmd)
{
  int	j;
  int	nb;

  if (str[i] == LABEL_CHAR)
    {
      j = 0;
      i += 1;
      while (my_cmp(&str[i], cmd->lab[j].label) == 0
	     && j < cmd->lablengh - 1)
	j++;
      nb = cmd->lab[j].adress - cmd->pc;
    }
  else
    nb = my_getnbr(&(str[i]));
  if ((param->param = realloc(param->param, param->lenght + IND_SIZE)) == NULL)
    exit(0);
  param->param[param->lenght + IND_SIZE - 1] = 0;
  param->param[param->lenght + IND_SIZE - 2] = 0;
  param->param[param->lenght + IND_SIZE - 1] |= nb;
  nb >>= 8;
  param->param[param->lenght + IND_SIZE - 2] |= nb;
  param->lenght += IND_SIZE;
}

void	put_to_param(t_param *param, char *str, int i, t_cmd *cmd)
{
  if (str[i] == 'r')
    {
      param->param[1] <<= 2;
      param->param[1] |= 1;
      registre(param, str, i);
    }
  else if (str[i] == DIRECT_CHAR)
    {
      param->param[1] <<= 2;
      param->param[1] |= 2;
      direct(param, str, i, cmd);
    }
  else
    {
      param->param[1] <<= 2;
      param->param[1] |= 3;
      indirect(param, str, i, cmd);
    }
}

void	params(char *str, int i, t_param *param, t_cmd *cmd)
{
  int	j;

  j = 4;
  param->param[1] = 0;
  while (str[i] != 0 && str[i] != ' ')
    i++;
  i++;
  while (str[i] != 0)
    {
      put_to_param(param, str, i, cmd);
      while (str[i] != 0 && str[i] != SEPARATOR_CHAR)
	i++;
      if (str[i] != 0)
	i++;
      j--;
    }
  param->param[1] <<= (2 * j);
}

int		parsing(char *str, t_cmd *cmd)
{
  int		i;
  int		ret;
  t_param	param;

  if ((param.param = malloc(2)) == 0)
    exit(0);
  if (str == 0)
    return (0);
  i = next_label(str);
  if (str[i] == ' ')
    i++;
  param.lenght = 2;
  ret = chose_func(&param, str, i, cmd);
  if (ret == -1)
    return (ret);
  if (ret == -2)
    return (0);
  my_putstr((char *)(param.param), cmd->fd, param.lenght);
  free(param.param);
  return (0);
}

/*
** parsing.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Fri Jan 25 16:45:04 2013 maxime lavandier
** Last update Sun Jan 27 19:45:52 2013 maxime lavandier
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
  if (nb > REG_NUMBER)
    {
      my_putstr("registre trop grand", 2, -1);
      exit(0);
    }
  if ((param->param = realloc(param->param, param->lenght + 1)) == 0)
    exit(0);
  param->param[param->lenght] = nbr;
  param->lenght += 1;
}

void	direct(t_param *param, char *str, int i)
{
  int	nb;

  if (str[i + 1] == LABEL_CHAR)
    {
      my_putstr("cas special non géré", 2, -1);
      exit(0);
    }
  nb = my_getnbr(&(str[i + 1]));
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

void	indirect(t_param *param, char *str, int i)
{
  int	nb;

  nb = my_getnbr(&(str[i]));
  if ((param->param = realloc(param->param, param->lenght + IND_SIZE)) == 0)
    exit(0);
  param->param[param->lenght + DIR_SIZE - 1] = 0;
  param->param[param->lenght + DIR_SIZE - 2] = 0;
  param->param[param->lenght + DIR_SIZE - 1] |= nb;
  nb = nb >> 8;
  param->param[param->lenght + DIR_SIZE - 2] |= nb;
  param->lenght += IND_SIZE;
}

void	put_to_param(t_param *param, char *str, int i)
{
  if (str[i] == 'r')
    {
      param->param[1] <<= 2;
      param->param[1] += 1;
      registre(param, str, i);
      /*
	registre
       */
    }
  else if (str[i] == '%')
    {
      param->param[1] <<= 2;
      param->param[1] += 2;
      direct(param, str, i);
    }
  else
    {
      param->param[1] <<= 2;
      param->param[1] += 3;
      indirect(param, str, i);
    }
}

void	params(char *str, int i, t_param *param)
{
  int	j;

  j = 3;
  param->param[1] = 0;
  while (str[i] != 0)
    {
      put_to_param(param, str, i);
      while (str[i] != 0 && str[i] != ',')
	i++;
      if (str[i] != 0)
	i++;
      j--;
    }
  param->param[1] <<= (2 * j);
}

int		parsing(char *str)
{
  int		i;
  t_param	param;

  if ((param.param = malloc(2)) == 0)
    exit(0);
  if (str == 0)
    return (0);
  if (check_cmd(str, &param) == -1)
    {
      my_putstr("error : le nombre de parametre est incorect", 2 , -1);
      exit(0);
    }
  i = next_label(str);
  if (str[i] == ' ')
    i++;
  params(str, i, &param);
  return (0);
}

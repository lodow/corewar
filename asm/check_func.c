/*
** check_func.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 23 20:16:10 2013 maxime lavandier
** Last update Wed Jan 30 14:22:39 2013 maxime lavandier
*/

#include "parse_cmd.h"

int	live_ldi_lldi(char *line, int i, t_param *param)
{
  my_putstr("coucou\n", 1, -1);
  if (line[i + 1] == 'i')
    param->param[0] = 0x1;
  else if (line[i + 1] == 'd')
    param->param[0] = 0xa;
  else if (line[i + 1] == 'l')
    param->param[0] = 0xe;
  while (line[i] != ' ' && line[i] != 0)
    i++;
  if (line[i] == ' ')
    i++;
  if (line[i] != '%')
    return (0);
  while (line[i] != ',' && line[i] != ':' && line[i] != 0)
    i++;
  if (line[i] != 0)
    return (0);
  return (1);
}

int	ld_st_lld(char *line, int i, t_param *param)
{
  my_putstr("dducou\n", 1, -1);
  if (line[i] == 'l' && line[i + 1] == 'l')
    param->param[0] = 0xd;
  else if (line[i] == 'l')
    param->param[0] = 0x2;
  else if (line[i] == 's')
    param->param[0] = 0x3;
  while (line[i] != ' ' && line[i] != 0)
    i++;
  if (line[i] == ' ')
    i++;
  if (line[i] != '%')
    return (0);
  while (line[i] != ',' && line[i] != 0)
    i++;
  if (line[i] == 0)
    return (0);
  while (line[i] != ',' && line[i] != ':' && line[i] != 0)
    i++;
  if (line[i] != 0)
    return (0);
  my_putstr("fffff\n", 1, -1);
  return (1);
}

void	add_sub_and_or_xor_sti_to_param(char *line, int i, t_param *param)
{
  if (line[i] == 'a' && line[i + 1] == 'd')
    param->param[0] = 0x4;
  else if (line[i] == 's' && line[i + 1] == 'u')
    param->param[0] = 0x5;
  else if (line[i] == 'a' && line[i + 1] == 'n')
    param->param[0] = 0x6;
  else if (line[i] == 'o' && line[i + 1] == 'r')
    param->param[0] = 0x7;
  else if (line[i] == 'x' && line[i + 1] == 'o')
    param->param[0] = 0x8;
  else if (line[i] == 's' && line[i + 1] == 't')
    param->param[0] = 0xb;
}

int	add_sub_and_or_xor_sti(char *line, int i, t_param *param)
{
  int	j;

  j = -1;
  add_sub_and_or_xor_sti_to_param(line, i, param);
  while (line[i] != ' ' && line[i] != 0)
    i++;
  if (line[i] == ' ')
    i++;
  if (line[i] != 'r')
    return (0);
  while (++j != 2)
    {
      while (line[i] != ',' && line[i] != 0)
	i++;
      if (line[i] == 0)
	return (0);
      i++;
      if (line[i] != 'r')
	return (0);
    }
  while (line[i] != ',' && line[i] != ':' && line[i] != 0)
    i++;
  if (line[i] != 0)
    return (0);
  return (1);
}

int	zjmp_fork_lfork(char *line, int i, t_param *param)
{
  if (line[i] == 'z')
    param->param[0] = 0x9;
  else if (line[i] == 'f')
    param->param[0] = 0xc;
  else if (line[i] == 'l')
    param->param[0] = 0xf;
  return (1);
}

int	aff(char *line, int i, t_param *param)
{
  param->param[0] = 0x10;
  return (1);
}

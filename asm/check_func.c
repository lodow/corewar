/*
** check_func.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 23 20:16:10 2013 maxime lavandier
** Last update Fri Jan 25 18:55:41 2013 maxime lavandier
*/

int	live_ldi_lldi(char *line, int i, t_param *param)
{
  if (line[i + 1] == 'i')
    param->type = 0x1;
  else if (line[i + 1] == 'd')
    param->type = 0xa;
  else if (line[i + 1] == 'l')
    param->type = 0xe;
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
  if (line[i] == 'l' && line[i + 1] == 'l')
    param->type = 0xd;
  else if (line[i] == 'l')
    param->type = 0x2;
  else if (line[i] == 's')
    param->type = 0x3;
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
  return (1);
}

int	add_sub_and_or_xor_sti(char *line, int i, t_param *param)
{
  while (line[i] != ' ' && line[i] != 0)
    i++;
  if (line[i] == ' ')
    i++;
  if (line[i] != 'r')
    return (0);
  while (line[i] != ',' && line[i] != 0)
    i++;
  if (line[i] == 0)
    return (0);
  i++;
  if (line[i] != 'r')
    return (0);
  while (line[i] != ',' && line[i] != 0)
    i++;
  if (line[i] == 0)
    return (0);
  i++;
  if (line[i] != 'r')
    return (0);
  while (line[i] != ',' && line[i] != ':' && line[i] != 0)
    i++;
  if (line[i] != 0)
    return (0);
  return (1);
}

int	zjmp_fork_lfork(char *line, int i, t_param *param)
{
  if (line[i] == 'z')
    param->type = 0x9;
  else if (line[i] == 'f')
    param->type = 0xc;
  else if (line[i] == 'l')
    param->type = 0xf;
  return (1);
}

int	aff(char *line, int i, t_param *param)
{
  param->type = 0x10;
  return (1);
}

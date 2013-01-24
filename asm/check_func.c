/*
** check_func.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 23 20:16:10 2013 maxime lavandier
** Last update Thu Jan 24 14:51:57 2013 maxime lavandier
*/

int	live_ldi_lldi(char *line, int i)
{
  return (1);
}

int	ld_st_lld(char *line, int i)
{
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

int	add_sub_and_or_xor_sti(char *line, int i)
{
  return (1);
}

int	zjmp_fork_lfork(char *line, int i)
{
  return (1);
}

int	aff(char *line, int i)
{
  return (1);
}

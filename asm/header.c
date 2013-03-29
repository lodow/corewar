/*
** header.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Jan 22 14:30:06 2013 maxime lavandier
** Last update Fri Mar 29 14:08:57 2013 adrien dellamaggiora
*/

#include <stdlib.h>
#include <stdio.h>
#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"
#include "../misc/nb_func.h"

void	error_indir(int nb)
{
  my_putstr("Warning Indirection to far line ", 2, -1);
  my_put_nbr(nb, 2);
  my_putstr("\n", 2, 1);
}

void	label_tofar(char *str, int nb)
{
  int	i;

  i = 0;
  my_putstr("Label ", 2, -1);
  while (str[i] != 0 && str[i] != ' ' && str[i] != SEPARATOR_CHAR)
    my_putstr(&str[i++], 2, 1);
  my_putstr(" undefine line ", 2, -1);
  my_put_nbr(nb, 2);
  my_putstr("\n", 2, 1);
}

char    *getname(char *name)
{
  char	*res;
  int	i;

  i = my_strlen(name);
  if ((res = malloc(i + 4)) == NULL)
    put_malloc_error();
  i = 0;
  while (name[i] != '\0')
    {
      res[i] = name[i];
      i++;
    }
  res[i - 1] = 'c';
  res[i] = 'o';
  res[i + 1] = 'r';
  res[i + 2] = '\0';
  return (res);
}

int	my_addbuf(char *file, t_cmd *cmd, int lengh)
{
  int	i;
  int	j;

  if ((cmd->file = realloc(cmd->file, cmd->sizefile + lengh)) == NULL)
    put_malloc_error();
  i = cmd->sizefile;
  j = 0;
  while (j <= lengh)
    {
      ((char *)cmd->file)[i] = file[j];
      ++i;
      ++j;
    }
  cmd->sizefile += lengh;
  return (0);
}

int		put_header(t_header *header, t_cmd *cmd, char *name)
{
  int		magic;
  int		i;

  magic = COREWAR_EXEC_MAGIC;
  header->magic = *((int*)switch_endian((char*)&(magic), sizeof(int)));
  header->prog_size = *((int*)switch_endian((char*)&(header->prog_size),
					    sizeof(int)));
  if ((cmd->file = malloc(sizeof(t_header))) == NULL)
    put_malloc_error();
  i = 0;
  while (i < sizeof(t_header))
    {
      ((char *) cmd->file)[i] = ((char *) header)[i];
      ++i;
    }
  cmd->sizefile = sizeof(t_header);
  return (0);
}

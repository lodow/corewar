/*
** header.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Jan 22 14:30:06 2013 maxime lavandier
** Last update Thu Mar 28 16:39:41 2013 maxime lavandier
*/

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

int		put_header(t_header *header, t_cmd *cmd, char *name)
{
  int		fd;
  mode_t	flag;
  int		magic;
  char		*str;

  str = getname(name);
  flag = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  if ((fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, flag)) == -1)
    return (-1);
  magic = COREWAR_EXEC_MAGIC;
  header->magic = *((int*)switch_endian((char*)&(magic), sizeof(int)));
  header->prog_size = *((int*)switch_endian((char*)&(header->prog_size),
					    sizeof(int)));
  my_putstr((char*)header, fd, sizeof(t_header));
  free(str);
  return (fd);
}

/*
** header.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Jan 22 14:30:06 2013 maxime lavandier
** Last update Wed Jan 30 15:28:15 2013 Welanor
*/

#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"

char    *getname(char *name)
{
  char	*res;
  int	i;

  i = my_strlen(name);
  if ((res = malloc(i + 4)) == NULL)
    return (NULL);
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

  flag = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  if ((fd = open(getname(name), O_WRONLY | O_CREAT | O_TRUNC, flag)) == -1)
    return (-1);
  magic = COREWAR_EXEC_MAGIC;
  header->magic = *((int*)switch_endian((char*)&(magic), sizeof(int)));
  header->prog_size = *((int*)switch_endian((char*)&(header->prog_size),
					    sizeof(int)));
  my_putstr((char*)header, fd, sizeof(t_header));
  return (fd);
}

/*
** fillfile.c for fillfile in /home/dellam_a/Projet/corewar/corewar/asm
**
** Made by adrien dellamaggiora
** Login   <adrien dellamaggiora@epitech.eu>
**
** Started on  Thu Jan 24 16:58:24 2013 adrien dellamaggiora
** Last update Mon Jan 28 20:24:54 2013 Welanor
*/

#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"

char	*getname(char *name)
{
  char	*res;
  int	i;

  i = my_strlen(name);
  if ((res = malloc(i + 4)) == NULL)
    return (NULL);
  i = 0;
  while (name[i] != '\0' && name[i] != 's')
    {
      res[i] = name[i];
      i++;
    }
  res[i++] = 'c';
  res[i++] = 'o';
  res[i++] = 'r';
  res[i] = 0;
  return (res);
}

void	fillfile(t_header *header, t_cmd *cmd, char *name)
{
  int	fd;
  int	flag;
  int	magic;

  flag = (O_CREAT & ~S_IRUSR & ~S_IWUSR & ~S_IRGRP & ~S_IROTH) | O_WRONLY;
  header->prog_size = cmd->pc;
  if ((fd = open(getname(name), flag)) == -1)
    exit(0);
  magic = COREWAR_EXEC_MAGIC;
  header->magic = *((int*)switch_endian((char*)&(magic), sizeof(int)));
  my_putstr((char*)header, fd, sizeof(t_header));
  my_putstr(cmd->file, fd, cmd->sizefile);
  return ;
}

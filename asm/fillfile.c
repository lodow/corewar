/*
** fillfile.c for fillfile in /home/dellam_a/Projet/corewar/corewar/asm
** 
** Made by adrien dellamaggiora
** Login   <adrien dellamaggiora@epitech.eu>
** 
** Started on  Thu Jan 24 16:58:24 2013 adrien dellamaggiora
** Last update Thu Jan 24 17:53:13 2013 Welanor
*/

#include "asm.h"
#include "parse_cmd.h"

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

void	fillfile(t_header *header, t_cmd *cmd)
{
  int	fd;
  int	flag;
  int	end;

  flag = (O_CREAT & ~S_IRUSR & ~S_IWUSR & ~S_IRGRP & ~S_IROTH) | O_WRONLY;
  end = sizeof(t_header) + cmd->sizefile;
  if ((fd = open(getname(header->prog_name), flag)) == -1)
    exit(0);
  my_putstr(cmd->file, fd, end);
  return ;
}

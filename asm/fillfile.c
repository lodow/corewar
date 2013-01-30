/*
** fillfile.c for fillfile in /home/dellam_a/Projet/corewar/corewar/asm
**
** Made by adrien dellamaggiora
** Login   <adrien dellamaggiora@epitech.eu>
**
** Started on  Thu Jan 24 16:58:24 2013 adrien dellamaggiora
** Last update Wed Jan 30 10:33:27 2013 Welanor
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

/*
** check_cmd.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 23 19:35:15 2013 maxime lavandier
** Last update Fri Feb  1 15:37:11 2013 maxime lavandier
*/

#include <stdlib.h>
#include "parse_cmd.h"

int	next_label(char *line)
{
  int	i;

  i = 0;
  while (line[i] != 0 && line[i] != ' ' && line[i] != ':')
    i++;
  if (line[i] == ' ' || line[i] == 0)
    return (0);
  while (line[i] == ' ' || line[i] == ':')
    i++;
  return (i);
}

void	line_to_instruction(char *line, char *instruction, int i)
{
  int	j;

  j = 0;
  while (line[i] != ' ')
    {
      instruction[j] = line[i];
      i++;
      j++;
    }
  instruction[j] = 0;
}

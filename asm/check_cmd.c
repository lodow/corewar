#include <stdlib.h>
#include "parse_cmd.h"

int	next_label(char *line)
{
  int	i;

  i = 0;
  while (line[i] != 0 && line[i] != ' ' && line[i] != LABEL_CHAR)
    i++;
  if (line[i] == ' ' || line[i] == 0)
    return (0);
  while (line[i] == ' ' || line[i] == LABEL_CHAR)
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

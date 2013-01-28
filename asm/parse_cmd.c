/*
** parse_cmd.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 13:51:50 2013 maxime lavandier
** Last update Mon Jan 28 13:16:14 2013 Welanor
*/

#include "parse_cmd.h"

char	*sub_space(char *str)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(my_strlen(str) + 1)) == NULL)
    exit(0);
  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (i > 1 && (str[i - 1] != ' ' && str[i - 1] != '\t'
		    && (str[i] == ' ' || str[i] == '\t')))
	res[j++] = ' ';
      else if (str[i] != ' ' && str[i] != '\t' && str[i] != 0)
	res[j++] = str[i];
      i++;
    }
  if (res[0] == 0)
    return (res);
  if (res[j - 1] == ' ')
    res[j - 1] = 0;
  else
    res[j] = 0;
  return (res);
}

int	parse_cmd(char *line, t_header *header, t_cmd *cmd)
{
  if (line == NULL || header == NULL || cmd == NULL)
    return (-1);
  line = sub_space(line);
  if (line[0] == '\0')
    return (0);
  return (0);
}

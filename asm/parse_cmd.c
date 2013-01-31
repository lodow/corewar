/*
** parse_cmd.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 13:51:50 2013 maxime lavandier
** Last update Thu Jan 31 06:23:52 2013 maxime lavandier
*/

#include "parse_cmd.h"
#include "asm.h"

char	*sub_space(char *str)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(my_strlen(str) + 1)) == NULL)
    exit(0);
  i = 0;
  j = 0;
  res[0] = 0;
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
  if (line == NULL || header == NULL || cmd == NULL || my_strlen(line) <= 1)
    return (-1);
  line = sub_space(line);
  if (line[0] == '\0')
    return (0);
  printf("cmd->pc = %d\n", cmd->pc);
  parsing(line, cmd);
  changepc(line, &(cmd->pc));
  return (0);
}

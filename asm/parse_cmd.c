#include "parse_cmd.h"
#include "asm.h"

char	*sub_space(char *str)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(my_strlen(str) + 1)) == NULL)
    put_malloc_error();
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
  if (header == NULL || cmd == NULL)
    return (-1);
  if (my_strlen(line) <= 1)
    return (0);
  line = sub_space(line);
  if (line[0] == '\0' || line[0] == '\n' || line[0] == COMMENT_CHAR)
    {
      free(line);
      return (0);
    }
  if (parsing(line, cmd) != 0)
    {
      free(line);
      return (-1);
    }
  if (line[0] != COMMENT_CHAR && line[0] != 0)
    changepc(line, &(cmd->pc));
  free(line);
  return (0);
}

/*
** label.c for label in /home/welanor/Projet/corewar/asm
** 
** Made by Welanor
** Login   <welanor@welanor>
** 
** Started on  Mon Jan 28 12:40:17 2013 Welanor
** Last update Thu Jan 31 15:14:59 2013 Welanor
*/

#include "parse_cmd.h"
#include "asm.h"

extern	t_op	op_tab[];

int	findlabel(char *line)
{
  char	*labelchar;
  int	i;
  int	k;
  int	j;

  i = 0;
  while (line[i] != LABEL_CHAR && line[i] != '\0')
    i++;
  if (line[i] == LABEL_CHAR && line[i + 1] == ' ')
    {
      labelchar = LABEL_CHARS;
      k = i - 1;
      while (k > 0)
        {
          j = 0;
          while (line[k] != labelchar[j] && labelchar[j] != '\0')
            j++;
          if (labelchar[j] == '\0')
            return (0);
          k--;
        }
      return (1);
    }
  return (0);
}

t_cmd		*my_realloc(t_cmd *cmd, int size)
{
  int		i;
  t_tablabel	*tmp;

  if ((tmp = malloc(size)) == NULL)
    return (NULL);
  if (cmd->lablengh == 0)
    {
      cmd->lab = tmp;
      return (cmd);
    }
  i = 0;
  while (i < cmd->lablengh)
    {
      tmp[i].label = my_strdup((cmd->lab[i]).label);
      tmp[i].adress = cmd->lab[i].adress;
      i++;
    }
  i = 0;
  while (i < cmd->lablengh)
    {
      free(cmd->lab[i].label);
      i++;
    }
  cmd->lab = tmp;
  return (cmd);
}

t_cmd		*addlabel(char *line, t_cmd *cmd)
{
  int		i;
  int		j;
  char		*str;

  i = 0;
  while (line[i] != LABEL_CHAR && line[i] != '\0')
    i++;
  if ((str = malloc(i + 1)) == NULL)
    exit(0);
  j = 0;
  while (j < i)
    {
      str[j] = line[j];
      j++;
    }
  str[j] = 0;
  if ((cmd = my_realloc(cmd, sizeof(t_tablabel) * (cmd->lablengh + 2)))
      == NULL)
    exit(0);
  cmd->lab[cmd->lablengh].label = str;
  cmd->lab[cmd->lablengh].adress = cmd->pc;
  cmd->lablengh += 1;
  return (cmd);
}

t_cmd	*recuplabel(t_cmd *cmd, char **file)
{
  int	i;
  char	*line;

  i = 0;
  cmd->lablengh = 0;
  cmd->pc = 0;
  while (file[i] != NULL)
    {
      line = sub_space(file[i]);
      if (line[0] != COMMENT_CHAR
	  && line[0] != 0
	  && my_begincmp(line, NAME_CMD_STRING) == 0
	  && my_begincmp(line, COMMENT_CMD_STRING) == 0)
	{
	  printf("%s\n", line);
	  if (findlabel(line) == 1)
	    cmd = addlabel(line, cmd);
	  changepc(line, &(cmd->pc));
	  printf("%d\n", cmd->pc);
	}
      free(line);
      i++;
    }
  return (cmd);
}

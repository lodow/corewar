/*
** parse_cmd.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 13:51:50 2013 maxime lavandier
** Last update Fri Jan 25 10:59:46 2013 Welanor
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
   if (res[j] == ' ')
     res[j] = 0;
   else
     res[j] = 0;
   free(str);
   return (res);
}

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

int	parse_cmd(char *line, t_header *header, t_cmd *cmd)
{
  if (line == NULL || header == NULL || cmd == NULL)
    return (-1);
  line = sub_space(line);
  if (line[0] == '\0')
    return (0);
  if (findlabel(line) == 1)
    cmd = addlabel(line, cmd);
  if (line[0] != '#')
    fillcmdfile(cmd, line);
  return (0);
}

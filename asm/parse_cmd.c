/*
** parse_cmd.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 13:51:50 2013 maxime lavandier
** Last update Wed Jan 23 17:13:47 2013 Welanor
*/

#include "parse_cmd.h"

char	*sub_space(char *str)
{
  int	i;
  int	j;
  char	*res;

  if ((res = malloc(my_strlen(str))) == NULL)
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
   if (res[j - 1] == ' ')
     res[j - 1] = 0;
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
  while(str[i] != LABEL_CHAR && str[i] != '\0')
    i++;
  if (str[i] == LABEL_CHAR)
    {
      k = i;
      while (k >= 0)
	{
	  labelchar = LABEL_CHAR;
	  j = 0;
	  while (str[k] != labelchar[j] && labelchar[j] != '\0')
	    j++;
	  if (labelchar[j] == '\0')
	    return (0);
	  k--;
	}
      return (1);
    }
  return (0);
}

t_cmd	*addlabel(char *line, t_cmd *cmd)
{
  int	i;
  int	j;
  char	*str;

  i = 0;
  while (str[i] != LABEL_CHAR && str[i] != '\0')
    i++;
  if ((str = malloc(i + 1)) == NULL)
    exit(0);
  j = 0;
  while (j < i)
    {
      str[j] = line[j];
      j++;
    }
  if ((cmd->lab = realloc(cmd->lab, sizeof(t_tablabel) * cmd->lablengh))
      == NULL)
    exit(0);
  cmd->lab[cmd->lablengh].label = str;
  cmd->lab[cmd->lablengh].adress = cmd->pc;
  cmd->lablengh += 1;
  return(cmd);
}

int	parse_cmd(char *line, t_header *header, t_cmd *cmd)
{
  int	i;

  i = 0;
  if (line == NULL || header == NULL || cmd == NULL)
    return (-1);
  line = sub_space(line);
  if (line[0] == '\0')
    return (0);
  if (findlabel(line) == 1)
    cmd = addlabel(line, cmd);
  printf("%s\n", line);
  return (0);
}

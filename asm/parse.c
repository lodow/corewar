/*
** parse.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed Jan 16 13:02:05 2013 maxime lavandier
** Last update Thu Mar 28 17:50:02 2013 maxime lavandier
*/

#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"
#include "../misc/nb_func.h"

int	recup_name(char *line, t_header *header, t_cmd *cmd)
{
  int	i_line;
  int	i_name;

  cmd->nom = 1;
  if (line == NULL || header == NULL)
    return (-1);
  i_name = 0;
  i_line = my_strlen(NAME_CMD_STRING);
  while (line[i_line] != '"' && line[i_line] != 0)
    i_line++;
  if (line[i_line] != 0)
    i_line++;
  while (line[i_line] != 0 && line[i_line] != '"' && i_name < PROG_NAME_LENGTH)
    {
      header->prog_name[i_name] = line[i_line];
      i_line++;
      i_name++;
    }
  if (i_name == PROG_NAME_LENGTH || line[i_line] == 0)
    {
      my_putstr("Name parse error\n", 2, 17);
      exit(0);
    }
  header->prog_name[i_name] = 0;
  return (0);
}

void	recup_comment(char *line, t_header *header, t_cmd *cmd)
{
  int	i_line;
  int	i_comment;

  cmd->com = 1;
  if (line == NULL || header == NULL)
    return ;
  i_comment = 0;
  i_line = my_strlen(COMMENT_CMD_STRING);
  while (line[i_line] != '"' && line[i_line] != 0)
    i_line++;
  if (line[i_line] != 0)
    i_line++;
  while (line[i_line] != 0 && line[i_line] != '"'
	 && i_comment < COMMENT_LENGTH)
    {
      header->comment[i_comment] = line[i_line];
      i_line++;
      i_comment++;
    }
  if (i_comment == COMMENT_CHAR || line[i_line] == 0)
    {
      my_putstr("Comment parse error\n", 2, 20);
      exit(0);
    }
  header->comment[i_comment] = 0;
}

int	next_the_header(char **file)
{
  int	i;

  i = 0;
  while ((file[i] != 0) && (file[i + 1] != 0) &&
	 ((file[i][0] == COMMENT_CHAR) || (file[i + 1][0] == COMMENT_CHAR)))
    {
      i++;
    }
  return (i);
}

void	put_error(int line)
{
  my_putstr("Syntax error line ", 2, -1);
  my_put_nbr(line + 1, 2);
  my_putstr("\n", 2, 1);
}

int		parse(char **file, char *name)
{
  t_header	header;
  t_cmd		cmd;

  cmd.nom = cmd.com = 0;
  cmd.nb = next_the_header(file) - 1;
  my_memsetc(&header, sizeof(t_header), 0);
  if ((cmd.file = malloc(8 + PROG_NAME_LENGTH + COMMENT_LENGTH)) == NULL)
    put_malloc_error();
  recuplabel(&cmd, file);
  header.prog_size = cmd.pc;
  cmd.pc = 0;
  while (file[++cmd.nb])
    if (my_begincmp(file[cmd.nb], NAME_CMD_STRING) && cmd.nom == 0)
      recup_name(file[cmd.nb], &header, &cmd);
    else if (my_begincmp(file[cmd.nb], COMMENT_CMD_STRING) && cmd.com == 0)
      {
	recup_comment(file[cmd.nb], &header, &cmd);
	cmd.fd = put_header(&header, &cmd, name);
      }
    else if (parse_cmd(file[cmd.nb], &header, &cmd) == -1)
      put_error(cmd.nb);
  freelabel(cmd);
  free(cmd.file);
  return (0);
}

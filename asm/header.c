/*
** header.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Jan 22 14:30:06 2013 maxime lavandier
** Last update Tue Jan 22 16:07:19 2013 maxime lavandier
*/

#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"

void	put_lenght(t_cmd *cmd, t_header *header)
{
  int	*file;
  char	*name;

  name = (char *) (cmd->file);
  file = (int *) &(name[PROG_NAME_LENGTH + 4]);
  file[0] = header->prog_size;
}

void	put_name(t_cmd *cmd, t_header *header)
{
  int	i;
  char	*name;

  name = (char *) (cmd->file);
  i = 0;
  while (header->prog_name[i] != 0)
    {
      name[i + 4] = header->prog_name[i];
      i++;
    }
  while (i < PROG_NAME_LENGTH + 4)
    {
      name[i + 4] = 0;
      i++;
    }
}

void	put_comment(t_cmd *cmd, t_header *header)
{
  int	i;
  char	*name;

  name = (char *) (cmd->file);
  i = 0;
  while (header->comment[i] != 0)
    {
      name[i + 8 + PROG_NAME_LENGTH] = header->comment[i];
      i++;
    }
  while (i < COMMENT_CHAR + 8)
    {
      name[i + PROG_NAME_LENGTH + 8] = 0;
      i++;
    }
}

int	put_header(t_cmd *cmd, t_header *header)
{
  int	*file;

  file = (int *) (cmd->file);
  if (file == 0)
    return (-1);
  file[0] = COREWAR_EXEC_MAGIC;
  put_name(cmd, header);
  put_lenght(cmd, header);
  put_comment(cmd, header);
  return (0);
}

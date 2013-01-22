/*
** header.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Jan 22 14:30:06 2013 maxime lavandier
** Last update Tue Jan 22 15:06:39 2013 maxime lavandier
*/

#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"

int	magic(t_cmd *cmd, t_header *header)
{
  int	*file;
  char	*name;
  int	i;

  file = (int *) (cmd->file);
  name = (char *) (cmd->file);
  if (file == 0)
    return (-1);
  file[0] = COREWAR_EXEC_MAGIC;
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
  return (0);
}

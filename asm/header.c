/*
** header.c for corewar in /home/lavand_m//projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Tue Jan 22 14:30:06 2013 maxime lavandier
** Last update Wed Jan 30 11:35:18 2013 Welanor
*/

#include "asm.h"
#include "parse_cmd.h"
#include "../misc/op.h"
#include "../misc/str_func.h"

/*void	put_lenght(t_cmd *cmd, t_header *header)
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
}*/

char    *getname(char *name)
{
  char	*res;
  int	i;

  i = my_strlen(name);
  printf("%s\n", name);
  if ((res = malloc(i + 4)) == NULL)
    return (NULL);
  i = 0;
  while (name[i] != '\0' && name[i] != 's')
    {
      res[i] = name[i];
      i++;
    }
  res[i++] = 'c';
  res[i++] = 'o';
  res[i++] = 'r';
  res[i] = 0;
  return (res);
}

int		put_header(t_header *header, t_cmd *cmd, char *name)
{
  int		fd;
  mode_t	flag;
  int		magic;

  flag = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  /*flag = (((((O_CREAT & ~S_IRUSR) & ~S_IWUSR) & ~S_IRGRP) & ~S_IROTH) | O_WRONLY);*/
  if ((fd = open(getname(name), O_WRONLY | O_CREAT | O_TRUNC, flag)) == -1)
    return (-1);
  magic = COREWAR_EXEC_MAGIC;
  header->magic = *((int*)switch_endian((char*)&(magic), sizeof(int)));
  header->prog_size = *((int*)switch_endian((char*)&(header->prog_size), sizeof(int)));
  my_putstr((char*)header, fd, sizeof(t_header));
  return (fd);
}

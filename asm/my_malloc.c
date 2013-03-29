/*
** my_malloc.c for corewar in /home/maxime/Bureau/projet/actu/corewar/asm
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Thu Mar 28 16:32:59 2013 maxime lavandier
** Last update Fri Mar 29 00:02:39 2013 Adrien Della Maggiora
*/

#include "parse_cmd.h"
#include "asm.h"

void	put_malloc_error()
{
  my_putstr("Can’t perform malloc", 2, -1);
  exit(0);
}

void		write_infile(char *name, char *file, int lengh)
{
  int		fd;
  mode_t	flag;
  char		*str;

  str = getname(name);
  flag = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  if ((fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, flag)) == -1)
    return ;
  my_putstr(file, fd, lengh);
  free(str);
}

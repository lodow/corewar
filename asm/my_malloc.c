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

/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Fri Jan 18 19:14:23 2013 adrien dellamaggiora
*/

#include "../misc/op.h"
#include "../misc/get_file.h"
#include "asm.h"

int	main(int argc, char **argv, char **envp)
{
  int	fd;
  char	**file;

  if (argc > 1)
    {
      if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
	  my_putstr("File ");
	  my_putstr(argv[1]);
	  my_putstr(" not accessible\n");
	  return (0);
	}
      file = get_data_ffile(fd);
      if (parse(file) == -1)
	my_putstr("parse error\n");
    }
  else
    my_putstr("No file\n");
}

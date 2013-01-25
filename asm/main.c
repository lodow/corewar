/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Fri Jan 25 11:17:23 2013 Welanor
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
	  my_putstr("File ", 2, 5);
	  my_putstr(argv[1], 2, -1);
	  my_putstr(" not accessible\n", 2, 16);
	  return (-1);
	}
      file = get_data_ffile(fd);
      if (file == 0 || file[0] == 0)
	{
	  my_putstr("error file\n", 2, 11);
	  return (-1);
	}
      if (parse(file, argv[1]) == -1)
	my_putstr("parse error\n", 2, 12);
    }
  else
    my_putstr("No file\n", 2, 8);
  return (0);
}

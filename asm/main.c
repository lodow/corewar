/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Wed Jan 16 13:03:07 2013 maxime lavandier
*/

#include "../misc/op.h"
#include "../misc/get_file.h"

int	main(int argc, char **argv, char **envp)
{
  int	fd;
  char	**file;

  if (argc < 2 && ((fd = open(file, O_RDONLY)) == -1))
    {
      my_putstr("file error\n");
      return (0);
    }
  file = get_data_ffile(fd);
  if (parse(file) == -1)
    my_putstr("parse error\n");
}

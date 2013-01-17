/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"include.h"

int	get_bin_file(const char *filename, char **file)
{
  char	*tmp;
  int	fd;
  int	tsize;
  char	buff[4096];
  int	nbread;

  (*file) = NULL;
  tsize = 0;
  nbread = 1;
  if ((filename == NULL) || ((fd = open(filename, O_RDONLY)) == -1))
    return (-1);
  while (nbread > 0)
    {
      nbread = read(fd, buff, 4096);
      if ((tmp = malloc((tsize + nbread) * sizeof(char))) == NULL)
        return (-1);
      my_strncpy(tmp, (*file), tsize);
      free((*file));
      (*file) = tmp;
      my_strncpy(&((*file)[tsize]), buff, nbread);
      tsize += nbread;
    }
  close(fd);
  return (tsize);
}

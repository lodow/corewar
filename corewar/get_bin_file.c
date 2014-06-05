#include	"include.h"

int	get_bin_file(int fd, char **file)
{
  char	*tmp;
  int	tsize;
  char	buff[BIN_BUFFER];
  int	nbread;

  (*file) = NULL;
  tsize = 0;
  nbread = 1;
  if (fd == -1)
    return (0);
  while (nbread > 0)
    {
      nbread = read(fd, buff, BIN_BUFFER);
      if ((tmp = malloc((tsize + nbread) * sizeof(char))) == NULL)
        return (-1);
      my_strncpy(tmp, (*file), tsize);
      free((*file));
      (*file) = tmp;
      my_strncpy(&((*file)[tsize]), buff, nbread);
      tsize += nbread;
    }
  return (tsize);
}

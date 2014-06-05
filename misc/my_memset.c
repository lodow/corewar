#include	<stdlib.h>

void	*my_memsetc(void *ptr, int size, int value)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = ptr;
  if (tmp != NULL)
    while (i < size)
      {
        tmp[i] = value;
        i += 1;
      }
  return (ptr);
}

void	*my_memseti(void *ptr, int size, int value)
{
  int	i;
  int	*tmp;

  i = 0;
  tmp = ptr;
  if (tmp != NULL)
    while (i < size)
      {
        tmp[i] = value;
        i += 1;
      }
  return (ptr);
}

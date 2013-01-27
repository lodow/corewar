/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Sun Jan 27 17:10:34 2013 luc sinet
*/

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

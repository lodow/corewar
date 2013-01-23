/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	<stdlib.h>

void	my_memset(void *ptr, int osize, char value)
{
  int	i;
  char	*ptrc;

  ptrc = ptr;
  i = 0;
  if (ptrc != NULL)
    while (i < osize)
      {
        ptrc[i] = value;
        i++;
      }
}

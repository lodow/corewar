/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include	"str_func.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if ((src != NULL) && (dest != NULL))
    while (i < n)
      {
        dest[i] = src[i];
        i++;
      }
  return (dest);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != '\0')
      i++;
  return (i);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i++] != '\0');
  i = write(1, str, i);
}


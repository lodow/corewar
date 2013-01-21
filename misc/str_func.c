/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Fri Jan 18 16:31:20 2013 adrien dellamaggiora
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
    {
      while (str[i] != '\0')
        i++;
    }
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

int	my_strcmp(char *src, char *str)
{
  int	i;

  i = 0;
  while (str[i] == src[i] && src[i] != 0 && str[i] != 0)
    i++;
  if (str[i] == src[i])
    return (1);
  else
    return (0);
}

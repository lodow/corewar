/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Jan 21 14:01:32 2013 maxime lavandier
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

void	my_putstr(char *str, int fd, int strlen)
{
  int	len;

  len = 0;
  if (str != NULL)
    {
      if (strlen == -1)
        {
          while (str[len++] != '\0');
          strlen = len;
        }
      len = write(fd, str, strlen);
    }
}

int	my_begincmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != 0 && str2[i] != 0)
    {
      if (str1[i] != str2[i])
        return (0);
      i++;
    }
  if (str2[i] != 0)
    return (0);
  return (1);
}

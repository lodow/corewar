#include "str_func.h"

char	*my_strdup(char *str)
{
  char	*res;
  int	i;

  i = 0;
  while (str[i])
    i++;
  if ((res = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (s1[i])
    i++;
  while (s2[x])
    s1[i++] = s2[x++];
  s1[i] = '\0';
  return (s1);
}

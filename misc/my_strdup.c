/*
** my_str.c for my_str in /home/welanor/Projet/corewar/corewar/misc
** 
** Made by Welanor
** Login   <welanor@welanor>
** 
** Started on  Thu Jan 24 13:38:20 2013 Welanor
** Last update Thu Jan 24 15:03:42 2013 Welanor
*/

#include "str_func.h"

char	*my_strdup(char *str)
{
  char	*res;
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  if ((res = malloc(i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != 0)
    {
      res[i] = str[i];
      i++;
    }
  res[i] = 0;
  return (res);
}

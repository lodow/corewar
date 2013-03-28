/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include <stdlib.h>

int	my_swap_char(char *a, char *b);

char	*my_evil_str(char *str)
{
  int	len;
  int	i;
  int	j;

  i = 0;
  if (str != NULL)
    {
      len = 0;
      while (str[len] != '\0')
        len++;
      while (i < len)
        {
          j = 0;
          while (j < i)
            {
              my_swap_char(&str[i], &str[j]);
              j = j + 1;
            }
          i = i + 1;
        }
    }
  return (str);
}

char	*recur_fill_str_w_nbr(unsigned int nb, char *base, int baselen, int n)
{
  char	*str;
  char	v;

  if (nb == 0)
    {
      if ((str = malloc((n + 1) * sizeof(char))) != NULL)
        str[n] = '\0';
      return (str);
    }
  str = recur_fill_str_w_nbr(nb / baselen, base, baselen, n + 1);
  if (str != NULL)
    {
      v = base[nb % baselen];
      str[n] = v;
    }
  return (str);
}

char	*my_uint_strbase(unsigned int nb, char *base)
{
  char	*res;
  int	baselen;

  baselen = 0;
  while ((base != NULL) && (base[baselen] != '\0'))
    baselen++;
  if (baselen < 2)
    return (NULL);
  if (nb != 0)
    res = recur_fill_str_w_nbr(nb, base, baselen, 0);
  else if ((res = malloc(2 * sizeof(char))) != NULL)
    {
      res[0] = base[0];
      res[1] = '\0';
    }
  return (my_evil_str(res));
}


/*
** test.c for test in /home/sinet_l//exo
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Thu Oct 11 10:36:50 2012 luc sinet
** Last update Tue Jan 22 13:47:53 2013 luc sinet
*/

#include <stdlib.h>

char    *my_revstr(char *str)
{
  int   a;
  int   lenght;
  char  let;

  a = 0;
  lenght = my_strlen(str) - 1;
  while (a < lenght)
    {
      let = str[a];
      str[a++] = str[lenght];
      str[lenght--] = let;
    }
  return (str);
}

void	fill_str(int nb, int sign, char *res, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      res[i++] = nb % 10 + '0';
      nb /= 10;
    }
  if (sign == -1)
    res[i++] = '-';
  res[i] = '\0';
  res = my_revstr(res);
}

char	*nb_to_str(int nb)
{
  char	*res;
  int	sign;
  int	size;
  int	tmp_nb;

  sign = 1;
  size = 1;
  if (nb < 0)
    {
      nb = -nb;
      sign = -sign;
    }
  tmp_nb = nb;
  if (nb == 0)
    tmp_nb = 1;
  while (((tmp_nb /= 10)) > 0)
    size++;
  if (sign == -1)
    res = malloc(size + 2);
  else
    res = malloc(size + 1);
  fill_str(nb, sign, res, size);
  return (res);
}

int main(int ac, char **av)
{
  printf("%s", nb_to_str(atoi(av[1])));
}

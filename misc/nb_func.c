/*
** my_getnbr.c for my_getnbr in /home/sinet_l//ratrapage
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Oct 20 11:27:34 2012 luc sinet
** Last update Wed Jan 23 20:42:21 2013 maxime lavandier
*/

#include <stdlib.h>
#include "str_func.h"

int	my_getnbr(char *s1)
{
  int	nb;
  int	i;
  int	sign;

  nb = 0;
  i = 0;
  sign = 1;
  while (s1[i] == '-' || s1[i] == '+')
    {
      if (s1[i] == '-')
	sign = -sign;
      i++;
    }
  while (s1[i] >= '0' && s1[i] <= '9')
    {
      if (((nb * 10) / 10) != nb)
	  return (0);
      nb = nb * 10 + (s1[i] - 48);
      i++;
    }
  return (nb * sign);
}

int	my_put_nbr(int nb, int fd)
{
  if (nb == -2147483648)
    {
      my_putstr("-2147483648", fd, 11);
      return (0);
    }
  if (nb < 0)
    {
      my_putstr("-", fd, 1);
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, fd);
  my_putstr(nb % 10 + 48, fd, 1);
  return (0);
}

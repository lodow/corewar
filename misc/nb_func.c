/*
** my_getnbr.c for my_getnbr in /home/sinet_l//ratrapage
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Sat Oct 20 11:27:34 2012 luc sinet
** Last update Sat Jan 26 19:17:51 2013 luc sinet
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
  char	res;

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
  res = nb % 10 + 48;
  my_putstr(&res, fd, 1);
  return (0);
}

void			print_hexa(char *mem, int nb)
{
  int                   i;
  char                  *hexa;
  unsigned char         tmp;

  i = 0;
  hexa = "0123456789ABCDEF";
  while (i < nb)
    {
      tmp = mem[i];
      my_putstr("0x", 1, 2);
      my_putstr(&hexa[tmp / 16], 1, 1);
      my_putstr(&hexa[tmp % 16], 1, 1);
      if (i != nb - 1)
	my_putstr(",", 1, 1);
      i++;
    }
}
